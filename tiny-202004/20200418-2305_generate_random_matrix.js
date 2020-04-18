//console.log();

var ar = [];

var col = 60;
var row = col;

var fn = () => Math.ceil(Math.random()*20);

ar.push("[");
for (var r = 0; r < row; r++) {
  if (r>0) ar.push(",");
  ar.push("[");
  for (var c = 0; c < col; c++) {
    if (c>0) ar.push(",");
    ar.push(fn());
  }
  ar.push("]");
}
ar.push("]");
 
console.log(ar.join(""))
