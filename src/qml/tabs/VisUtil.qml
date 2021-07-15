import QtQuick 2.12
import QtQml 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Window 2.12
import Qt.labs.platform 1.1
import osab.xyz.DashBoard 1.0
import osab.xyz.QtVIS 1.0

import "../snippets"
import "../settings"

ColumnLayout {
  id: root
  width: parent.width
  height: parent.height
  RowLayout {
    Rectangle {
      width: parent.width
      Rectangle {
        id: file_label
        width: parent.width * 0.8
        Label {
          text: file_diag.file
        }
      }
      Button {
        width: parent.width * 0.2
        height: 100
        text: "Open File"
        anchors.left: file_label.right
        onClicked: file_diag.open()
      }
    }
    FileDialog {
      id: file_diag
      title: "Open VIS file"
      fileMode: FileDialog.OpenFile
    }
  }
}
