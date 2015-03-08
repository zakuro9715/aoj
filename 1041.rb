while true 
  n = gets.to_i
  if n == 0 
    break
  end
  a = 0
  for i in 0...n / 4 
    a += gets.to_i
  end
  puts a
end
