
module Stacklike

    def stk
        @stack ||= []
    end

    def add_to_stack(obj)
        stk.push(obj)
    end
end

class Stack
    include Stacklike
end

def t
a = [1,2,3]
a.find_all do |x|
    x + 1
end
end
p t 
