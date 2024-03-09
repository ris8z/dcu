
function printer(callback, n1, n2){
    console.log(callback(n1, n2))
}


printer(function(a, b){
    return a + b
}, 1, 20)
