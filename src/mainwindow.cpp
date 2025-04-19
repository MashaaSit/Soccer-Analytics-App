#include "../include/mainwindow.h"
#include "../include/Attack.h"


bool stringToBool(const QString &str) {
    return str == "true" || str == "1" || str == "True";
}

int timeDifference(const QPair<int, int> &time1, const QPair<int, int> &time2) {
    int seconds1 = time1.first * 60 + time1.second;
    int seconds2 = time2.first * 60 + time2.second;
    return seconds2 - seconds1;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->showMaximized();
    ui->gamefieldLabel->setImage();
    ui->prevAttackButton->setEnabled(false);


    setWindowTitle("Soccer Analytics App");
    setWindowIcon(QIcon(":/appIcon.png"));
    if (this->windowIcon().isNull()) {
        qDebug() << "Не удалось загрузить изображение!";
    }
    QFile CSVFile(":/PassData - Лист1.csv");
    if (CSVFile.open(QIODevice::ReadOnly)) {
        QTextStream Stream(&CSVFile);

        Attack last_attack;
        passes_container last_passes_set;
        bool first = true;
        while (Stream.atEnd() == false) {
            QString LineData = Stream.readLine();
            QStringList Data = LineData.split(",");

            if (first) {
                last_attack.setTeam(Data.at(7).toInt());

                ui->firstTeamLabel->setText(QString::number(Data.at(7).toInt()));

                 ui->firstTeamLabel->setAlignment(Qt::AlignCenter);

                last_passes_set.push_back(Pass(qMakePair(Data.at(3).toInt(), Data.at(4).toInt()),
                                               qMakePair(Data.at(8).toDouble(), Data.at(9).toDouble()),
                                               qMakePair(Data.at(10).toDouble(), Data.at(11).toDouble()),
                                               stringToBool(Data.at(12)), stringToBool(Data.at(13))));
                first = false;
            } else {
                if (Data.at(7).toInt() == last_attack.getTeamId()) {
                    if (timeDifference(last_passes_set.back().getTime(),
                                       qMakePair(Data.at(3).toInt(), Data.at(4).toInt())) < 4) {
                        last_passes_set.push_back(Pass(qMakePair(Data.at(3).toInt(), Data.at(4).toInt()),
                                                       qMakePair(Data.at(8).toDouble(), Data.at(9).toDouble()),
                                                       qMakePair(Data.at(10).toDouble(), Data.at(11).toDouble()),
                                                       stringToBool(Data.at(12)), stringToBool(Data.at(13))));
                    }
                } else {
                    last_attack.setPasses(last_passes_set);
                    ui->gamefieldLabel->getAttackContainer().push_back(last_attack);
                    last_passes_set.clear();
                    last_attack.clear();

                    last_attack.setTeam(Data.at(7).toInt());
                    if (ui->secondTeamLabel->text().isEmpty()) {
                        ui->secondTeamLabel->setText(QString::number(Data.at(7).toInt()));

                        ui->secondTeamLabel->setAlignment(Qt::AlignCenter);
                    }
                    last_passes_set.push_back(Pass(qMakePair(Data.at(3).toInt(), Data.at(4).toInt()),
                                                   qMakePair(Data.at(8).toDouble(), Data.at(9).toDouble()),
                                                   qMakePair(Data.at(10).toDouble(), Data.at(11).toDouble()),
                                                   stringToBool(Data.at(12)), stringToBool(Data.at(13))));
                }
            }
            // ui->gamefieldLabel->getAttackContainer().push_back(Attack(team_id, ));
        }
        if (!last_passes_set.empty()) {
            last_attack.setPasses(last_passes_set);
            ui->gamefieldLabel->getAttackContainer().push_back(last_attack);
        }
    }
    CSVFile.close();

    connect(ui->drawAttackButton, &QPushButton::clicked, ui->gamefieldLabel, &GameFieldLabel::nextAttackButtonClicked);
    // connect(ui->drawPassButton, &QPushButton::clicked, ui->gamefieldLabel, &GameFieldLabel::drawPassButtonClicked);
    connect(ui->prevAttackButton, &QPushButton::clicked, ui->gamefieldLabel, &GameFieldLabel::prevAttackButtonClicked);

    

}
void MainWindow::resizeEvent(QResizeEvent *event) {
    int windowWidth = event->size().width();
    int windowHeight = event->size().height();

    // Размер поля = 60% от окна
    int fieldWidth = windowWidth * 0.8;
    int fieldHeight = windowHeight * 0.8;

    int rightPannelW = windowWidth*0.2;
    int rightPannelH = windowHeight*0.2;
    // Меняем размер gamefieldLabel
    ui->gamefieldLabel->resize(fieldWidth, fieldHeight);
    ui->rightPanel->resize(rightPannelW,rightPannelH);
    ui->firstTeamLabel->adjustSize();
    ui->label->adjustSize();
    ui->secondTeamLabel->adjustSize();
    // Обновляем отображение
    ui->gamefieldLabel->update();

    QMainWindow::resizeEvent(event);
}



MainWindow::~MainWindow() {
    delete ui;
}
