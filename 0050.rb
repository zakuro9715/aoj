ap, pa, a, p = 'apple', 'peach', 'a' * 10000, 'p' * 10000
puts gets.gsub(ap, a).gsub(pa, p).gsub(a, pa).gsub(p, ap)
