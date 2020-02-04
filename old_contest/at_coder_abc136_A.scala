object Main extends App{
    // Here your code !
 
    // 1文字ずつ分割
    val split = scala.io.StdIn.readLine().split(' ')
    val A = split(0).toString.toInt
    val B = split(1).toString.toInt
    val C = split(2).toString.toInt
 
    val ans = C - A + B
    if (ans > 0){
        println(C-A+B)
    }else{
        println(0)
    }
    
}
