import QtQuick 2.12
import QtQml 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Window 2.12



import "tabs"
import "settings"

ApplicationWindow {
  id: window
  visible: true
  minimumHeight: 200
  minimumWidth: 600
  height: 600
  width: 800
  title: qsTr("WIP-QT")

  Settings {
	id: sett
  }
    
//  TabBar {
//	id: main_tab_bar
//	width: parent.width
//	Repeater {
//        model: ["Dashboard", "Device Information"]
//	  TabButton {
//		hoverEnabled: true
//		id: tab_button
//        font.pixelSize: sett.font_size
//		text: qsTr(modelData)
//		ToolTip.visible: hovered
//		ToolTip.delay: 1000
//		ToolTip.timeout: 5000
//		ToolTip.text: qsTr(modelData)
//	  }
//	}
//  }
//  StackLayout {
//	width: parent.width
//	height: parent.height - main_tab_bar.height
//	anchors {
//	  top: main_tab_bar.bottom
//	  left: window.left
//	  right: window.right
//	  bottom: button_bar.top
//	}
//	currentIndex: main_tab_bar.currentIndex
//    DashBoard {
//      height: parent.height
//      width: window.width
//    }
//    DevInfo {
//      height: parent.height
//      width: window.width
//    }
//  }
//  footer: RowLayout {
//	id: button_bar
//	width: parent.width
//	anchors {
//	  bottom: window.bottom
//	  left: window.left
//	  right: window.right
//	}
//	Button {
//      font.pixelSize: sett.font_size
//	  implicitWidth: button_bar.width / 2
//	  text: qsTr("Exit")
//      onClicked: function() {window.close()}
//	}
//	Button {
//      font.pixelSize: sett.font_size
//	  implicitWidth: button_bar.width / 2
//	  text: qsTr("Settings")
//	}
//  }
}
