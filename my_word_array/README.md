# プログラムの概要
## プログラムの実行方法例
``` terminal
$ gcc *.c
$ ./a.out main.c
```
## 挙動
コマンドライン引数に指定したファイルの中の単語(isalnumがtrueになる文字で構成されている)を辞書順にソートしてカウントを出力する\
コマンドライン引数が指定されていないとき、stdinから入力を受け付ける

## 修正が必要な点
* 計算効率が悪い
	* add_word.cのadd_word関数でstrcmpを使っているところの処理で二分探索を使えばO(n) -> O(log n)にできる
	* arrayではなくlistでwordを保持すればadd_word.cのshift_arrayと同じ処理をO(n) -> O(1)にできる
