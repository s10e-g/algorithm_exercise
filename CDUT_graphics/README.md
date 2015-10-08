Usage
-----
Simply run the binary file.

**Input Format**
The first line contains 2 space-separated numbers *n*,*m* - the number of vertics on candidate polygon to be clipped and the number of vertics on clipping (window) polygon.
The second line contains 2n space-separated numbers xi, yi - the coordinate of vertics on candidiate polygon to be clipped.
The third line contains 2m space-separated numbers xi, yi - the coordinate of vertics on clipping polygon.

**Output Format**
Output contains n lines, each line indicate a polygon clipped by the clipping polygon.

**Example**
```bash
$a.out
4 4
3 1 3 3 0 4 5 4
1 5 2 2 5 0 1 0
```
output:
```bash
(3,1) (3,1.33333) (3.15385,1.23077) 
(1.5,3.5) (1,3.66667) (1,4) (1.33333,4)
```
