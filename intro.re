= はじめに

本書はプログラミングを始めたばかりの人を対象としません。
初心者を脱し、その先へと進むプログラマへのメッセージをまとめたものです。

本書では特にことわりがない限りC++17を前提とします。

仕事をしている中で「もっとこうしたほうがいい」というアドバイスをすることや、
「この機能はこういう仕組みなんだよ」と解説をする機会が多くあります。

幾度も説明するうちに、本でも書いたほうがいいのではないかと思い、筆をとった次第です。

後半、サンプルコードのコメントの大部分が英語となっております。
油断しておりました。
まあ、C++プログラマの大部分が英語が読めると信じております。
読めない人はコードから気合で察してください（すいません）。

== まえおき

僕は「いなむのみたま」と申します。

僕の得意分野はライブラリプログラミングです。
ライブラリを作るためには、アプリケーションだけを作るなら一生使わないようなC++の機能を山のように使うことになります。
なので、一般のC++プログラマより少しだけC++に詳しいです。

C++の守り神として日々C++のコンパイラをいじめています。
いなむのみたまのかみ(@mitama_rs)という名前でTwitterに生息しており、Twitterで迷えるC++プログラマを救う活動をしています。

さて、突然ですがぼくの苦労話です。
とあるベンチャー企業に雇われてC++やらRustやらを書いて一年が経ちました。
ジョブチェンジしたてのC++プログラマに少々の苦悩が立ちはだかりました。

 * スマートポインタ使ってないどころか、newですらなくてmallocを使うソースコード
 * 完全下位互換STLともいうべき、オレオレ実装
 * 3万を超えるヘッダを有し、そびえ立つライブラリ
 * ドキュメントもないし意味不明な過去の遺産
 * 「templateは難しいからできるだけ使うな」とか言う人
 * 全然自動化されてないCMakeLists

というかだいたいの苦悩はOpen Cascade Technologyというライブラリが原因です。

C++に限らず、汚いコードは非常に汚いです。
「もうお前C++書くな」と言いたいこともあります。

汚いコードを書いているプログラマは決してサボっているわけではありません。
それどころか、僕よりも何倍もの時間コードを書いているように見えます。
ライブラリを使えばいい処理を手で書いたり、
同じような少し違う処理をたくさん書いたり、
意味のない条件分岐を書いたり、
使わない変数を書いたり、
とにかくありとあらゆる間違った技法を凝らしてコーディングを複雑にしているのです。

悪いことに、CMakeListsをキレイにしたり、テストを充実させるのに当てる時間もありません。
実装で手一杯なのですから。

幸いにもベンチャー企業はとても動きやすいです、クソコードを見たら焼き尽くすことにしています。
すでにあるコードを見て新人が真似をするなんてことになったら耐えられません。
クソコードを1行放置するとそのうち100行になると思ってやってます。
ぶっちゃけると本書は、そのときの僕が流した涙やついたため息をまとめたものです。
幸いなことに、教育とレビューで生まれる前にクソコードを滅ぼす程度にはチームが安定してきたのでこの本の続編が執筆されることはないでしょう。

=== @<b>{C++は難しいのか？}

C++は難しいです、でもほとんどの場合は必要な難しさだと思っています。

C++はものすごく高機能です。
簡単なことを簡単にコーディングするには向いていないかもしれません。
しかし、ライブラリを書いている僕からすると天国のような言語です。
優れた実行時性能と柔軟なインターフェイスを備えたライブラリを書きたいとき、いつもC++は最高の言語でした。
なんだかんだPythonも使いますが、実行時性能が足りなければC++で書き直せばいいのだという謎の安心感がありました（もちろんPythonのライブラリも優秀ですが）。

実行時性能が優れていなくてもよく、専用のインターフェイスがあればよく、またC++の過去の遺産もない場合、
C++は無駄に複雑で難しく見えるのかもしれません。

簡単に書ける言語はほとんどの場合、何かを切り捨てることで簡単になっているのです。
そういう意味では、C++は難しいです。
様々な機能がユーザーに開放されています。
それらを真に必要としたとき、C++はあなたの助けとなってくれるでしょう。
逆にそれらを真に必要としない場合、C++を開発言語に選択するのは間違っているかもしれません。
そういう人はとなりのPython部屋に行くべきなのです。

@<b>{C++の規格の難解さにブチ切れることもありますけどね！}
