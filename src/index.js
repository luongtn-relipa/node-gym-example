const addon1 = require("../build/Release/addon1");
const addon2 = require("../build/Release/addon2");
console.log("addon1: ", addon1);
console.log("addon2: ", addon2);
console.log(addon1.hello());
console.log(addon2.hello());
console.log("Sum 1: ", addon1.sum([1, 2, 3, 4, 5]));
console.log("Sum 2: ", addon2.sum([1, 2, 3, 4, 5]));

// const addon3 = require("../build/Release/addon3");
// console.log("addon3: ", addon3);
// console.log(addon3.add(4, 6));
// console.log(addon3.isPrime(7));

// const addon4 = require("../build/Release/addon4");
// console.log("addon4: ", addon4);
// console.log(addon4.add(4, 6));
// console.log(addon4.isPrime(7));
// addon4.mainFunction();

// const addon5 = require("../build/Release/addon5");
// console.log("addon5: ", addon5);
// console.log(addon5.add(4, 6));
// console.log(addon5.isPrime(7));

// const addon6 = require("../build/Release/addon6");
// console.log("addon6: ", addon6);
// console.log(addon6.add(4, 6));
// console.log(addon6.isPrime(7));
