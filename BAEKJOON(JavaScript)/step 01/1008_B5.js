const fs = require('fs')
const [a, b] = fs.readFileSync(process.platform == 'linux' ? '/dev/stdin' : '../example.txt').toString().trim().split(' ').map(Number);
console.log(a/b)