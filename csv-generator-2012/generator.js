var fs = require('fs');

console.log("Generation of a dummy table...")

function generate(nLines, nColumns, nColSize, bUniqueCells, bNumeric, sBaseFileName) {

//  var nLines = 100000;
//  var nColumns = 12;
//  var nColSize = 31;
//  var bUniqueCells = false;
//  var bNumeric = false;
  var COL_SEPARATOR = ";";
  var LINE_SEPARATOR = "\n";

  var fMBytes = nColumns * (nColSize+1) * nLines / 1024 / 1024;

  var sSuff = (bUniqueCells?"uniq":"same") + "_" + (bNumeric?"num":"str")
  sSuff = sSuff + "_" + nLines + "Rx" + nColumns + "Cx" + nColSize + "B";
  sSuff = sSuff + "_" + Math.round(fMBytes) + "MB"

  var sFileName = sBaseFileName.replace(/\.?csv$/,"") + "_" + sSuff + ".csv";

  console.log("generating " + sFileName + "...");

  var arDesc = [];
  arDesc.push((bUniqueCells?"unique":"same") + " cells in columns");
  arDesc.push("" + nLines + " rows x " + nColumns + " cols");
  arDesc.push("" + nColSize + " chars/cell");
  arDesc.push("" + (nColumns * (nColSize+1)) + " Bytes/row");
  arDesc.push("" + Math.round(fMBytes * 10) / 10 + " MBytes/table");

  of = fs.createWriteStream(sFileName);

  for (var iLine=0; iLine <= nLines; iLine++) {
    var arRow = [];
    if (0==iLine) {
      for (iColumn=0; iColumn<nColumns; iColumn++) {
        arRow.push("Column " + (iColumn+1));
      }
    } else {
      for (iColumn=0; iColumn<nColumns; iColumn++) {
        var sValue = null;
        if (!bNumeric && 0 == iColumn && (iLine-1) < arDesc.length) {
          sValue = arDesc[iLine-1];
          if (sValue.length < nColSize-1) {
            sValue = sValue + " ";
          }
        } else {
          if (bNumeric) {
            sValue = iColumn+1;
            if (bUniqueCells) {
              sValue = sValue + (iLine-1)*nColumns;
            }
          }
          else {
            sValue = "value-" + (iColumn+1);
            if (bUniqueCells) {
              sValue = sValue + "-" + (iLine+0);
            }
            sValue = sValue + "-";
          }
        }
        if (!bNumeric) {
          while (sValue.length < nColSize) { 
            sValue = sValue + "x";
          }
        }
        arRow.push(sValue);
      }
    }
    of.write(arRow.join(COL_SEPARATOR));
    of.write(LINE_SEPARATOR);
  }

  console.log("      done " + sFileName + ".");

  of.end()
}


var sBaseFile = "set.csv";

[100000].forEach(function(nLines) {
  [30].forEach(function(nColumns) {
    [false].forEach(function(bUniqueCells) {
      [23].forEach(function(nColSize) {
        generate(nLines, nColumns, nColSize, bUniqueCells, false, sBaseFile);
      });
      generate(nLines, nColumns, 1, bUniqueCells, true, sBaseFile);
    });
  });
});


console.log("done.")
