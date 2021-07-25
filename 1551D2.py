import itertools
from dataclasses import dataclass

@dataclass
class TableView:
    line_length: int
    col_length: int


class DrawATable:
    VERTICAL_PIECE = 'abc'
    HORIZONTAL_PIECE = 'xyz'

    def __init__(self, n, m):
        self.n = n
        self.m = m
        self.table = list()
        for _ in range(self.n):
            self.table.append(['1'] * self.m)

    def gen(self, piece):
        yield from itertools.cycle(piece)

    def draw__vertical(self):
        src = self.gen(DrawATable.VERTICAL_PIECE)
        for row in range(self.n):
            for c in range(self.m):
                if self.table[row][c] != '1':
                    continue
                pick = next(src)
                if row > 0 and self.table[row - 1][c] == pick:
                    pick = next(src)
                if c   > 0 and self.table[row][c - 1] == pick:
                    pick = next(src)
                try:
                    self.table[row][c] = pick
                    self.table[row + 1][c] = pick
                except IndexError:
                    pass

    def draw__horizontal(self, start_line, start_col, line_length, col_length, piece = 'xy'):
        # print('drawing', start_line, start_col, line_length, col_length, piece)
        src = self.gen(piece)
        for row in range(start_line, start_line + line_length):
            for c in range(start_col, start_col + col_length, 2):
                pick = next(src)
                if row > 0 and self.table[row - 1][c] == pick:
                    pick = next(src)
                if c   > 0 and self.table[row][c - 1] == pick:
                    pick = next(src)
                try:
                    self.table[row][c] = pick
                    self.table[row][c + 1] = pick
                except IndexError:
                    pass

    def render_table(self):
        for line in self.table:
            print(''.join(line))


def check_from_left_top_corner(n, m):
    for i in range(1, 1 + n):
        for j in range(2, m + 1, 2):
            if (n - i) & 1:
                continue
            if (i & 1) and (j < m):
                continue
            yield [i, j]

def check(n, m, k):
    for w1, w2 in check_from_left_top_corner(n, m):
        if w1 * w2 == 2 * k:
            return ['YES', [TableView(w1, w2)]]
        if w1 < n and w2 < m:
            continue
        consumed = w1 * w2 // 2
        new_k = k - consumed
        table_views = [TableView(w1, w2)]
        # print('found', w1, w2)
        # print('consumed', consumed)
        for w1, w2 in check_from_left_top_corner(n - w1, m):
            if w1 * w2 == 2 * new_k:
                # print(f'1: {n - w1}x{m} {new_k}')
                table_views.append(TableView(w1, w2))
                return ['YES', table_views]
        for w1, w2 in check_from_left_top_corner(n, m - w2):
            if w1 * w2 == 2 * new_k:
                # print(f'{n}x{m - w2} {new_k}')
                table_views.append(TableView(w1, w2))
                return ['YES', table_views]
    return ['NO', []]

def solve():
    n, m, k = [int(x) for x in input().split()]
    a = DrawATable(n, m)
    if k == 0:
        if n & 1:
            print('NO')
            return
        print('YES')
        a.draw__vertical()
        a.render_table()
        return
    ans, table_views = check(n, m, k)
    if ans == 'YES':
        print('YES')
        if len(table_views) == 1:
            table_view = table_views[0]
            a.draw__horizontal(
                0,
                0,
                table_view.line_length,
                table_view.col_length
            )
        else:
            assert len(table_views) == 2
            if table_views[0].line_length == n:
                a.draw__horizontal(
                    0,
                    0,
                    table_views[0].line_length,
                    table_views[0].col_length
                )
                a.draw__horizontal(
                    0,
                    table_views[0].col_length,
                    table_views[1].line_length,
                    table_views[1].col_length,
                    piece = 'ef'
                )
            else:
                # assert table_views[1].col_length == m
                a.draw__horizontal(
                    0,
                    0,
                    table_views[1].line_length,
                    table_views[1].col_length
                )
                a.draw__horizontal(
                    table_views[1].line_length,
                    0,
                    table_views[0].line_length,
                    table_views[0].col_length,
                    piece = 'ef'
                )
        a.draw__vertical()
        a.render_table()
        return
    print('NO')

if __name__=='__main__':
    for _ in range(int(input())):
        solve()