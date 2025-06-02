const fs = require('fs');
const [A, B] = fs.readFileSync(process.platform == 'linux' ? '/dev/stdin' : '../example.txt').toString().trim().split('\n').map(Number);

console.log(A * (B % 10))
console.log(A * Math.floor(B % 100 / 10))
console.log(A * Math.floor(B / 100))
console.log(A * B)