import QtQuick 2.12
import QtQml 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Window 2.12

import osab.xyz.DashBoard 1.0
import osab.xyz.Map 1.0
import "../settings"

GridDisplay {
  id: root
  width: 100
  height: 100
  signal click();
  Connections {
    target: root
    function onClick() {
      console.log(mouse_area.mouseY, mouse_area.mouseX)
    }
  }
  MouseArea {
    id: mouse_area
    anchors.fill: root
    onClicked: root.click()
  }
}
