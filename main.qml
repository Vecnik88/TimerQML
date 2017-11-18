import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQml 2.2
// После того, как объект зарегистрирован в C++ слое
// его необходимо подключить в QML
import io.qt.Timer 1.0

Window {
    visible: true
    width: 400
    height: 400

    // А теперь добавляем объект
    Timer {
        id: clockCircle
        // позиционируем его и задаём размеры
        anchors.top: parent.top
        anchors.topMargin: 50
        anchors.horizontalCenter: parent.horizontalCenter
        width: 200
        height: 200

        // Определяем его свойства, которые Q_PROPERTY
        name: "clock"
        backgroundColor: "whiteSmoke"
        borderActiveColor: "LightSlateGray"
        borderNonActiveColor: "LightSteelBlue"

        // Добавляем текст, на который будет выставляться время таймера
        Text {
            id: textTimer
            anchors.centerIn: parent
            font.bold: true
            font.pixelSize: 24
        }

        // При изменении времени, помещаем это время на таймер
        onCircleTimeChanged: {
            textTimer.text = Qt.formatTime(circleTime, "mm:ss.zzz")
        }
    }

    Button {
        id: start
        text: "Start"
        onClicked: clockCircle.start(); // Запуск таймера
        anchors {
            left: parent.left
            leftMargin: 20
            bottom: parent.bottom
            bottomMargin: 20
        }
    }

    Button {
        id: stop
        text: "Stop"
        onClicked:  clockCircle.stop(); // остановка таймера
        anchors {
            horizontalCenter: parent.horizontalCenter
            bottom: parent.bottom
            bottomMargin: 20
        }
    }

    Button {
        id: clear
        text: "Clear"
        onClicked: clockCircle.clear(); // очистка таймера
        anchors {
            right: parent.right
            rightMargin: 20
            bottom: parent.bottom
            bottomMargin: 20
        }
    }
}
