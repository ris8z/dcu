
let obj = {
    "name": "John",
    "age": 47,
    sayHello: function(){
        console.log("Hello my name is " + this.name)
    }
}


obj.sayHello()
