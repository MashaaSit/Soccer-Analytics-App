#include "../include/GameFieldLabel.h"


GameFieldLabel::GameFieldLabel(QWidget *parent)
    : QLabel(parent) {
}

void GameFieldLabel::setImage() {
    if (!originalPixmap.load(":/gamefield_back.svg")) {
        qDebug() << "Не удалось загрузить изображение!";
    }
    resize(size());
    update();
}

void GameFieldLabel::resizeEvent(QResizeEvent *event) {
    QLabel::resizeEvent(event);
    if (!originalPixmap.isNull()) {
        scaledPixmap = originalPixmap.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    }
}


void GameFieldLabel::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.drawPixmap(0, 0, scaledPixmap);

    if (m_shouldDrawAttack && m_currentAttackToDraw < m_attacks.size()) {
        drawAttack(&painter);
    }
    if (m_shouldDrawPrevAttack && m_currentAttackToDraw > 0) {
        drawAttack(&painter);
    }


    QLabel::paintEvent(event);
}

void GameFieldLabel::clearDrawing() {
    auto *firstTeam = this->parentWidget()->findChild<QLabel *>("firstTeamLabel");
    auto *secondTeam = this->parentWidget()->findChild<QLabel *>("secondTeamLabel");
    firstTeam->setStyleSheet("background-color: #FFA680;border-radius: 4px;padding: 2px 4px;");
    secondTeam->setStyleSheet("background-color: #FFA680;border-radius: 4px;padding: 2px 4px;");
    m_shouldDrawAttack = false;
    m_shouldDrawPrevAttack = false;
}

void GameFieldLabel::nextAttackButtonClicked() {
    clearDrawing();

    if (m_attackCount < m_attacks.size()) {
        m_currentAttackToDraw = m_attackCount;
        m_shouldDrawPrevAttack = false;
        m_shouldDrawAttack = true;
        update();
        m_attackCount++;
    }

    updateButtonsState();
}

void GameFieldLabel::prevAttackButtonClicked() {
    clearDrawing();
    if (m_attackCount > 0) {
        m_attackCount--;

        m_currentAttackToDraw = m_attackCount;
        m_shouldDrawPrevAttack = true;
        m_shouldDrawAttack = false;
        update();
    }

    updateButtonsState();
}


void GameFieldLabel::drawAttack(QPainter *painter) {

    if (m_currentAttackToDraw >= m_attacks.size() || m_currentAttackToDraw < 0) return;
    const Attack &current_attack = m_attacks.at(m_currentAttackToDraw);


    auto teamIdStr = QString::number(current_attack.getTeamId());

    passes_container current_passes = current_attack.getPasses();
    QLabel *attackTeam = this->parentWidget()->findChild<QLabel *>("firstTeamLabel")->text() == teamIdStr
                             ? this->parentWidget()->findChild<QLabel *>("firstTeamLabel")
                             : this->parentWidget()->findChild<QLabel *>("secondTeamLabel");
    attackTeam->setStyleSheet("background-color: #FB8B5B;border: 6px solid #B4ACAC;border-radius:4px;");


    drawPasses(painter, current_passes);
}

void GameFieldLabel::drawPasses(QPainter *painter, passes_container &current_passes) {
    int fullWidth = scaledPixmap.width();
    int fullHeight = scaledPixmap.height();

    double scale_x = static_cast<double>(fullWidth) / 1128.0;
    double scale_y = static_cast<double>(fullHeight) / 687.0;


    double offsetLeft = (1128.0 - 1049.83) / 2.0 * scale_x; // ≈ 39.085 * scale_x
    double offsetTop = (687.0 - 679.82) / 2.0 * scale_y; // ≈ 3.59 * scale_y

    double fieldWidth = 1049.83 * scale_x;
    double fieldHeight = 679.82 * scale_y;

    for (auto &pass: current_passes) {

        double norm_x1 = pass.getPointFrom().first;
        double norm_y1 = pass.getPointFrom().second;
        double norm_x2 = pass.getPointTo().first;
        double norm_y2 = pass.getPointTo().second;


        double x1 = offsetLeft + (norm_x1 / 100.0) * fieldWidth;
        double y1 = offsetTop + ((100.0 - norm_y1) / 100.0) * fieldHeight;
        double x2 = offsetLeft + (norm_x2 / 100.0) * fieldWidth;
        double y2 = offsetTop + ((100.0 - norm_y2) / 100.0) * fieldHeight;

        QPen pen(Qt::red);
        pen.setWidth(2);
        pen.setStyle(Qt::SolidLine);
        pen.setCapStyle(Qt::RoundCap);
        pen.setJoinStyle(Qt::RoundJoin);
        painter->setPen(pen);
        painter->drawLine(QPointF(x1, y1), QPointF(x2, y2));
        double angle = std::atan2(y2 - y1, x2 - x1);


        const double arrowLength = 10.0;
        const double arrowAngle = M_PI / 6.0;


        QPointF arrowP1 = QPointF(
            x2 - arrowLength * std::cos(angle - arrowAngle),
            y2 - arrowLength * std::sin(angle - arrowAngle)
        );

        QPointF arrowP2 = QPointF(
            x2 - arrowLength * std::cos(angle + arrowAngle),
            y2 - arrowLength * std::sin(angle + arrowAngle)
        );


        QVector<QPointF> arrowHead = {QPointF(x2, y2), arrowP1, arrowP2};
        painter->drawPolygon(arrowHead);
    }
}

void GameFieldLabel::updateButtonsState() {
    auto *nextButton = this->parentWidget()->findChild<QPushButton *>("drawAttackButton");
    auto *prevButton = this->parentWidget()->findChild<QPushButton *>("prevAttackButton");

    if (nextButton) nextButton->setEnabled(m_attackCount < m_attacks.size());
    if (prevButton) prevButton->setEnabled(m_attackCount > 0);
}
