price = 2 # rubles each product
discounted_price = 1 # ruble

class sortable:
    def __init__(self, necessary, qfdp) -> None:
        self.necessary = necessary
        self.quantity_for_discounted_price = qfdp
    
    def __lt__(self, other):
        return self.quantity_for_discounted_price < other.quantity_for_discounted_price


def buy(products, quantity, i, rightmost):
    while quantity > 0:
        if rightmost == i:
            break
        if quantity > products[rightmost].necessary:
            quantity -= products[rightmost].necessary
            products[rightmost].necessary = 0
            rightmost -= 1
        else:
            products[rightmost].necessary -= quantity
            quantity = 0
    assert rightmost >= i
    return (rightmost, quantity)


def solve():
    n = int(input())
    products = [0] * n
    for i in range(n):
        necessary_quantity, discounted_quantity = [int(x) for x in input().split()]
        products[i] = sortable(necessary_quantity, discounted_quantity)
    products.sort()
    
    bought, paid, r = 0, 0, n - 1
    for i in range(n):
        assert paid >= bought
        if products[i].necessary == 0:
            continue
        if bought >= products[i].quantity_for_discounted_price:
            paid += discounted_price * products[i].necessary
        else:
            r, left = buy(products, products[i].quantity_for_discounted_price - bought, i, r)
            paid += price * (products[i].quantity_for_discounted_price - bought - left)
            bought += products[i].quantity_for_discounted_price - bought - left
            if r > i:
                assert left == 0
                paid += discounted_price * products[i].necessary
            if r == i:
                if products[i].necessary + bought < products[i].quantity_for_discounted_price:
                    paid += price * products[i].necessary
                else:
                    paid += price * (products[i].quantity_for_discounted_price - bought)
                    paid += discounted_price * (products[i].necessary + bought - products[i].quantity_for_discounted_price)
        bought += products[i].necessary
        products[i].necessary = 0
    return paid


if __name__=='__main__':
    print(solve())