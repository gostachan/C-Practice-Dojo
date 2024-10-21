# プログラムの概要
## 仕様
### 使用可能な関数 : write
* メモリ領域を標準出力に出力する関数を作成せよ。
* メモリ領域は、以下のように、3つの列に分けて出力すること。
	* 行の最初の文字のアドレス(16進数で表したアドレス)と、":" が出力さ れていること。
	* 以下の例を参照し、2文字ごとにスペースを含む16進数に、必要に応じて 追加のスペースを入れること。
	* アドレスにある要素を、表示文字に変換すること。
* 文字が表示文字ではない場合は、ドット“.”に置き換えられる
* 各行は、16文字で構成されていること。
* サイズが0の場合は、何も出力しないこと。
* 例)
```
$> ./ft_print_memory
000000010a161f40: 426f 6e6a 6f75 7220 6c65 7320 616d 696e Bonjour les amin
000000010a161f50: 6368 6573 090a 0963 0720 6573 7420 666f ches...c. est fo
000000010a161f60: 7509 746f 7574 0963 6520 7175 206f 6e20 u.tout.ce qu on
000000010a161f70: 7065 7574 2066 6169 7265 2061 7665 6309 peut faire avec.
000000010a161f80: 0a09 7072 696e 745f 6d65 6d6f 7279 0a0a ..print_memory..
000000010a161f90: 0a09 6c6f 6c2e 6c6f 6c0a 2000           ..lol.lol. .
$> ./ft_print_memory | cat -te
0000000107ff9f40: 426f 6e6a 6f75 7220 6c65 7320 616d 696e Bonjour les amin$
0000000107ff9f50: 6368 6573 090a 0963 0720 6573 7420 666f ches...c. est fo$
0000000107ff9f60: 7509 746f 7574 0963 6520 7175 206f 6e20 u.tout.ce qu on $
0000000107ff9f70: 7065 7574 2066 6169 7265 2061 7665 6309 peut faire avec.$
0000000107ff9f80: 0a09 7072 696e 745f 6d65 6d6f 7279 0a0a ..print_memory..$
0000000107ff9f90: 0a09 6c6f 6c2e 6c6f 6c0a 2000           ..lol.lol. .$
$>
```
* プロトタイプ例)
```
void *ft_print_memory(void *addr, unsigned int size);
```
* 関数が、addr を返すように実装すること。
## 学んだこと