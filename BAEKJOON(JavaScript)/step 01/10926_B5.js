const fs = require('fs');
const input = fs.readFileSync(process.platform == 'linux' ? '/dev/stdin' : '../example.txt').toString().trim();
console.log(input + '??!');