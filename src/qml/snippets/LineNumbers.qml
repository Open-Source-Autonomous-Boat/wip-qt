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

Column {
  id: root
  property var editor_area // Too lazy to change
  width: editor_area.numbers_margin
  Repeater {
    model: editor_area.file_lines
    Label {
      text: index
      color: "black"
      horizontalAlignment: Text.AlignRight
      width: editor_area.numbers_margin
    }
  }
}
