# 競技プログラミング用のコマンドラインツール置き場

## atq
復習キューを管理するコマンドラインツール．

### キューの中身を見る
```
atq look
```

### キューに問題を追加する
atq push を実行した後に，YYMMDD の形で復習する日付を入力し，その後に問題のURLを入力する．
例えば，
```
atq push
220617 
https://atcoder.jp/contests/abc253/tasks/abc253_f
```

### キューの問題を削除する
atq pop （問題番号）の形で実行する．例えば，
```
atq pop 2
```

## cnd
コンテスト用のディレクトリを用意するコマンドラインツール．
cnd （コンテスト名）の形で実行する．例えば，
```
cnd ABC256
```