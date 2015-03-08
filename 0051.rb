n = gets.to_i
n.times do
  s = gets.strip.split(//).map(&:to_i).sort
  puts s.reverse.join.to_i - s.join.to_i
end
