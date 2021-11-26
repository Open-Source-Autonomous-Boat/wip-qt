import QtQml 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Window 2.12
import QtPositioning 6.2
import QtWebEngine 2.12

import osab.xyz.DashBoard 1.0

import "../settings"

/* MapDisplay { */
/*   id: root */
/*   width: parent.width */
/*   height: parent.height */
/*   Component.onCompleted: { */
/*     var grid1 = Qt.createComponent("qrc:/qml/snippets/GridWrapper.qml"); */
/*     var grid_obj = grid1.createObject(root, {}); */
/*   } */
/*   // GridWrapper {} */
/* } */

WebEngineView {
  width: parent.width
  height: parent.height
  url: "https://map.google.com"
  // activeFocusOnPress: true
}
