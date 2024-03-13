
function add(a, b){
    return a + b
}

function printer(callback, n1, n2){
    console.log(callback(n1,n2))
}

printer(add, 1, 20)
