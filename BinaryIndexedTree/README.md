BinaryIndexedTree

これは転倒数を求める構造体である。
転倒数とは、配列をソートするのに最低で何回swapを行うかというものである。

関数addで用いている「x & -x」はLSB(Least Significant Bit)というもので、二進数で表現した時に初めて1が出てくるのは右から数えて何番目かというものである。
例えば5=101だからLSB(5)=1、4=100だからLSB(4)=3ということである。

また関数addでのfor文で「x < size」としているが、検索では「x <= size」というものばかりを見かけた。
しかし、長さがn（つまり引数が0～n-1）の配列に対して引数nを用いることになるため「<=」では不適切である（実際にごく稀ではあるが終了コード134が出力されるケースがある）。
そのため等号は削除した（数学的にも自明である）。

参考リンクhttps://atcoder.jp/contests/chokudai_S001/submissions/41214393

以上。
