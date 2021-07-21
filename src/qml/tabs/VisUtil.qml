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
  HeaderSnip{label_name: "VIS Editor"}
  Settings {
    id: sett
  }
  RowLayout {
    height: 200
    Rectangle {
      color: "red"
      id: file_label
      Layout.fillWidth: true
      Label {
        text: file_diag.file
      }
    }
    Button {
      text: "Open File"
      onClicked: file_diag.open()
    }
  }
  FileDialog {
    id: file_diag
    title: "Open VIS file"
    fileMode: FileDialog.OpenFile
  }
}
