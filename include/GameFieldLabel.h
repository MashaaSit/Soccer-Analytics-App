#ifndef GAMEFIELDLABEL_H
#define GAMEFIELDLABEL_H

#include "Attack.h"
#include <QLabel>
#include <QPainter>
#include <QPixmap>
#include <QResizeEvent>
#include <QDebug>
#include <QPushButton>
#include <cmath>
using attacks_container = QVector<Attack>;

class GameFieldLabel : public QLabel {
    Q_OBJECT

public:
    explicit GameFieldLabel(QWidget *parent = nullptr);

    void setImage();

    void resizeEvent(QResizeEvent *event) override;

    void paintEvent(QPaintEvent *event) override;

    attacks_container &getAttackContainer() { return m_attacks; }

    int &get_attackCount() { return m_attackCount; }

    QPixmap getOriginalPixmap() const { return originalPixmap; } // Геттер для originalPixmap
    QPixmap getScaledPixmap() const { return scaledPixmap; } // Геттер для scaledPixmap
    void setScaledPixmap(const QPixmap &pixmap) { scaledPixmap = pixmap; }

    void clearDrawing();

    void drawAttack(QPainter *painter);

    void drawPasses(QPainter *painter, passes_container &curr_passes);

    void updateButtonsState();

private:
    QPixmap originalPixmap;
    QPixmap scaledPixmap;
    attacks_container m_attacks;
    int m_attackCount;
    bool m_shouldDrawAttack = false;
    int m_currentAttackToDraw = -1;
    bool m_shouldDrawPrevAttack;

public slots:
    void nextAttackButtonClicked();


    void prevAttackButtonClicked();


signals:
    void changeTeamLabelStyle();
};

#endif // GAMEFIELDLABEL_H
