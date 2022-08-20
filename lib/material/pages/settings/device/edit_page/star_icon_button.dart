import 'package:flutter/material.dart';
import 'package:osab/db/actions.dart';

class FavoriteButton extends StatefulWidget {
  final VoidCallback? callback;
  final String id;

  const FavoriteButton({
    required this.callback,
    required this.id,
    super.key,
  });

  @override
  State<StatefulWidget> createState() {
    return _FavoriteButton();
  }
}

class _FavoriteButton extends State<FavoriteButton> {
  late Future<bool> status;
  @override
  void initState() {
    super.initState();
    status = _checkFav();
  }

  @override
  Widget build(BuildContext context) {
    return FutureBuilder(
        future: status,
        builder: ((context, snapshot) {
          Icon icon = const Icon(Icons.star_border_outlined);
          if (snapshot.connectionState == ConnectionState.done &&
              snapshot.hasData) {
            if ((snapshot.data as bool) == true) {
              icon = const Icon(Icons.star);
            }
          }
          return IconButton(
            onPressed: () {
              if (widget.callback != null) {
                widget.callback?.call();
              }
              setState(() {
                status = _checkFav();
              });
            },
            icon: icon,
          );
        }));
  }

  Future<bool> _checkFav() async =>
      (await DBActions.getFavoriteDevice()) == widget.id;
}
