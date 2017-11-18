#ifndef TIMER_H
#define TIMER_H

#include <QtQuick/QQuickPaintedItem>
#include <QColor>
#include <QBrush>
#include <QPen>
#include <QPainter>
#include <QTime>
#include <QTimer>

class Timer : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QColor backgroundColor READ backgroundColor WRITE setBackgroundColor NOTIFY backgroundColorChanged)
    Q_PROPERTY(QColor borderActiveColor READ borderActiveColor WRITE setBorderActiveColor NOTIFY borderActiveColorChanged)
    Q_PROPERTY(QColor borderNonActiveColor READ borderNonActiveColor WRITE setBorderNonActiveColor NOTIFY borderNonActiveColorChanged)
    Q_PROPERTY(qreal angle READ angle WRITE setAngle NOTIFY angleChanged)
    Q_PROPERTY(QTime circleTime READ circleTime WRITE setCircleTime NOTIFY circleTimeChanged)

public:
    explicit Timer(QQuickItem *parent);
    void paint(QPainter *painter) override;

    Q_INVOKABLE void clear();
    Q_INVOKABLE void start();
    Q_INVOKABLE void stop();

    QString name() const;
    QColor backgroundColor() const;
    QColor borderActiveColor() const;
    QColor borderNonActiveColor() const;
    qreal angle();
    QTime circleTime();

public slots:
    void setName(const QString name);
    void setBackgroundColor(const QColor backgroundColor);
    void setborderActiveColor(const QColor borderActiveColor);
    void setborderNonActiveColor(const QColor borderNonActiveColor);
    void setAngle(const qreal anglr);
    void setCircleTime(const QTime circleTime);

signals:
    void cleared();

    void nameChanged(const QString name);
    void backgroundColorChanged(const QColor backgroundColor);
    void borderActiveColorChanged(const QColor borderActiveColor);
    void borderNonActiveColorChanged(const QColor borderNonActiveColor);
    void angleChanged(const qreal angle);
    void circleTimeChanged(const QTime circleTime);

private:
    QString     m_name;                 // Название объекта, по большей части до кучи добавлено
    QColor      m_backgroundColor;      // Основной цвет фона
    QColor      m_borderActiveColor;    // Цвет ободка, заполняющий при прогрессе ободок таймера
    QColor      m_borderNonActiveColor; // Цвет ободка фоновый
    qreal       m_angle;                // Угол поворота графика типа пирог, будет формировать прогресс на ободке
    QTime       m_circleTime;           // Текущее время таймера

    QTimer      *internalTimer;         // Таймер, по которому будет изменяться время

};

#endif // TIMER_H
