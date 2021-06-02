import QtQuick 2.12
import QtQml 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Window 2.12

ApplicationWindow {
        id: window
        visible: true
        width: 340
        height: 480
        title: qsTr("WIP-QT")
        Rectangle {
        }

//        TabBar {
//                id: main_tab_bar
//                width: parent.width
//                Repeater {
//                        model: ["Dashboard"]
//                        TabButton {
//                                text: modelData
//                        }
//                }
//        }
//        StackLayout {
//                width: parent.width
//                height: parent.height - main_tab_bar.height
//                Rectangle {
//                    id: dashboard
//                    Text {
//                        text: qsTr("Hello World!")
//                        anchors.centerIn: parent
//                    }
//                }
//        }
}
