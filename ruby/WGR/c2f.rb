

c = File.read('t.dat').to_i
f = c * 9 / 5 + 32
o = File.new('t.out', 'w')
o.puts f
