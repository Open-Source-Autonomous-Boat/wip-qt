import QtQuick 2.12
import QtQml 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Window 2.12
import Qt.labs.platform 1.1
import osab.xyz.DashBoard 1.0

import "../snippets"
import "../settings"

ColumnLayout {
  id: root
  width: parent.width
  height: parent.height
  RowLayout {
    Button {
      width: 200
      height: 100
      text: "Click me!"
      onClicked: file_diag.open()
    }
    FileDialog {
      id: file_diag
      title: "Open VIS file"
      //folder: shortcuts.home
      //Component.onCompleted: true
    }
  }
}
