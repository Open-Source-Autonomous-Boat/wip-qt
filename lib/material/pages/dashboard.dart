import 'package:flutter/material.dart';
import './dashboard/cards.dart';

class AndroidDashBoard extends StatefulWidget {
  const AndroidDashBoard({super.key});
  @override
  State<StatefulWidget> createState() {
    return _AndroidDasBoard();
  }
}

class _AndroidDasBoard extends State<AndroidDashBoard> {
  @override
  Widget build(BuildContext context) => Column(children: [
        DashBoardCards.greetingCard(),
        Expanded(
            flex: 2,
            child: ListView(
              // children: [for (var value in DashBoardCards.list) value],
              children: DashBoardCards.list,
            ))
      ]);
}
