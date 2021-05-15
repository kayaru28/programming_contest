

### データ構造
|構造|用途|参考|
|-|-|-|
|vector         |変数列の順次格納|
|multiset       |変数列を順次格納＆ソート|
|que            |先入れ先出し　BFS|
|priorityque    |優先度順に先だし|
|stack          |先入れ後だし　DFS|abc138-D
|deque          |変数列の前方・後方データ挿入|zone2021-D
|map            |断続的な値をキーとする連想配列
|union find tree|要素間の連結関係
|segment tree   |区間アクセスが容易な木構造
|bit            |2進数とフラグ管理

<br>
<br>
<br>
<hr>

### 探索法
- 探索対象
  - 問題文の通りに単純全探索
  - あり得る通り数を全探索
  - 答えを全探索
- 探索方式
  - 全探索
    - bit全探索 (abc002-D)
    - 幅優先探索
    - 深さ優先探索(abc138-D)
    - 再帰探索
    - 順列全探索
  - 二分探索（abc077-C,abc023-D）
    - 特定値探索・・・bound系
    - 特定条件値探索
#### 特定手法
|方法|用途|参考|
|-|-|-|
|binary search  |昇順変数列への特定値の探索|
|depth first search |グラフへの特定値を順番に深く探索|
|breadth first search |グラフへの特定値を階層ごとに探索
|dijkstra | 負でない１以上の重みを辺が持つグラフへの最短経路探索
|Bellman-Ford | 負の値も含む辺が重みを持つグラフへの最短経路探索
|lower_bound | 数列への特定値に対するインデックス探索

<br>
<br>

### 動的計画法
|DPパターン|概要|参考問題|
|-|-|-|
|ナップサック|典型DPで、目的値及び制約を軸(添字)とするDPテーブル|JOI2013_D,JOI2015_D|
|区間 DP|制約の区間(左端と右端)を軸とするDPテーブル|JOI2015_D|
|bit DP|選択肢の順列の順序を軸とするDPテーブル|JOI2017_D|

<br>
<br>

### 論理演算
A xor B xor C = (A xor B) xor C
A xor B xor C = A xor B xor C xor X xor X = (A xor X) xor (B xor C xor X)

https://zero-kpr.hatenablog.com/entry/2020/01/17/084434