import 'package:flutter/material.dart';
import 'package:osab/db/db.dart';

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
  late final Future<bool> status;
  @override
  void initState() {
    super.initState();
    status = _checkFav();
  }

  @override
  Widget build(BuildContext context) {
    return FutureBuilder(builder: ((context, snapshot) {
      return IconButton(
        onPressed: widget.callback,
        icon: const Icon(Icons.star),
      );
    }));
  }

  Future<bool> _checkFav() async {
    DBClass db = await DBInstances.osab();
    List<OSABDataValues> data = OSABData().from(await db.getItem("devid"));
    if (data.isEmpty) {
      return false;
    }
    return true;
  }
}
