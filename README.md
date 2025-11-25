# ソート可視化プログラム
ソートを可視化するプログラムです.  

## 実装ソート一覧
- バブルソート
- クイックソート
- 選択ソート
- 挿入ソート
- ヒープソート

## 実行方法

それぞれプロジェクトのルートディレクトリにて,

- バブルソート : 
```bash
$ make bubble
```

- クイックソート : 
```bash
$ make quick
```

- 選択ソート : 
```bash
$ make choice
```

- 挿入ソート : 
```bash
$ make insertion
```

- ヒープソート : 
```bash
$ make heap
```

とコマンドを打てば実行されます.

## 片付け
実行すれば,オブジェクトファイルと実行ファイルが生成されます.  
それらを削除したいときは,
```bash
$ make clean
```
と打ちます.

### warningについて
実行時,
```bash
clang: warning: -lhg: 'linker' input unused [-Wunused-command-line-argument]
clang: warning: -framework Cocoa: 'linker' input unused [-Wunused-command-line-argument]
clang: warning: argument unused during compilation: '-L/usr/local/lib' [-Wunused-command-line-argument]
```
のような `warning` が出ます.  
これは,オブジェクトファイル生成時にリンクをしないよう,`-c`オプションをつけているにも関わらず,  
リンクをするためのオプションがあるという `warning` です。

原因として描画に使用しているライブラリ用のコンパイラドライバ `hgcc` にそのようなリンクオプションが含まれているためと予想されます.  
Makefileの効率的な差分ビルドのために,わざと残しています.
実行に問題はないので無視してください.
