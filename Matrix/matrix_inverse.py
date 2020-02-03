from fractions import Fraction

def get_indentity_matrix(n):
  m = [[Fraction(0,1)]*n for _ in xrange(n)]
  for i in xrange(n):
    m[i][i] = Fraction(1,1)
  return m

def inverse(matrix):
  n = len(matrix)
  I = get_indentity_matrix(n)
  m = []
  for i in xrange(n):
    m.append(matrix[i] + I[i])
  for i in xrange(n):
    idx = i
    for j in xrange(i+1,n):
      if abs(m[j][i]) > abs(m[idx][i]):
        idx = j
    #endfor
    if id != i:
      for j in xrange(i, 2*n):
        m[i][j], m[idx][j] = m[idx][j] , m[i][j]
    #endif
    for j in xrange(n):
      if j != i:
        factor = m[j][i] / m[i][i]
        for k in xrange(2*n):
          m[j][k] -= factor*m[i][k]
    #endfor
  #endfor
  for i in xrange(n):
    div = m[i][i]
    for k in xrange(2*n):
      m[i][k] /= div
  #endfor
  return [m[i][n:] for i in xrange(n)]


if __name__ == '__main__':
    ans = inverse([[Fraction(5),Fraction(2,3)],[Fraction(1,4),Fraction(5)]])
    print ans
