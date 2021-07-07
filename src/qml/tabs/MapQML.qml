import QtQuick 2.12
import QtQml 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Window 2.12
import osab.xyz.Map 1.0

ColumnLayout {
  id: root
  width: parent.width
  height: parent.height
  MapDisplay {
    width: parent.width
    height: parent.height
  }
}
