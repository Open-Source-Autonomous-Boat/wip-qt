import QtQuick 2.12
import QtQml 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Window 2.12

ApplicationWindow {
        id: window
        visible: true
        width: 600
        height: 800
        minimumHeight: 200
        minimumWidth: 400
        //maximumHeight: 600
        //maximumWidth: 800
        title: qsTr("WIP-QT")
  
		TabBar {
		  id: main_tab_bar
		  property int bar_font_size: Qt.application.font.pixelSize * 1.4
		  width: parent.width
		  Repeater {
			model: ["Dashboard", "Device Information", "Map", "Cache"]
			TabButton {
			  hoverEnabled: true
			  id: tab_button
			  font.pixelSize: main_tab_bar.bar_font_size
			  text: qsTr(modelData)
			  ToolTip.visible: hovered
			  ToolTip.delay: 1000
			  ToolTip.timeout: 5000
			  ToolTip.text: qsTr(modelData)
			}
		  }
		}
}
