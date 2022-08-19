import 'package:flutter/material.dart';

class TextStyles {
  static Text cardText(String aText) => Text(
        aText,
        style: const TextStyle(fontSize: 16.0),
      );
  static Widget sectionTitle(String aText, BuildContext aContext) => Padding(
      padding: const EdgeInsets.only(left: 21),
      child: Text(
        aText,
        style: TextStyle(
            color: Theme.of(aContext).colorScheme.secondary,
            fontSize: 14.0,
            fontWeight: FontWeight.bold),
      ));
}
