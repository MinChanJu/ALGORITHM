const fs = require('fs');
const [A, B, C] = fs.readFileSync(process.platform == 'linux' ? '/dev/stdin' : '../example.txt').toString().trim().split(' ').map(Number);
console.log(A + B + C)