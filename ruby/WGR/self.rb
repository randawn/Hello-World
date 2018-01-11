
puts 'top level'
puts "self is #{self}"

module N
    puts 'module n'
    puts "self is #{self}"
end

class C
    include N
    puts 'class define blk'
    puts "self is #{self}"

    def self.x
        puts 'clas method C.x'
        puts "self is #{self}"
    end

    def m
        puts 'inst method C#m'
        puts "self is #{self}"
    end

    module M
        puts "nest Modlue"
        puts "self is #{self}"
    end
end

def C.y
    puts 'cls method C.y'
    puts "self is #{self}"
end

class Z
    def Z.no_dot
        puts 'z dot no dot called'
    end
    puts no_dot
end

Z.no_dot
