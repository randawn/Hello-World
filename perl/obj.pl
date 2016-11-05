#!/usr/bin/env perl

use warnings;
use strict;


=begin AN_OBJECT_IS_SIMPLY_A_DATA_STRUCTURE;

use Scalar::Util 'blessed';

my $ref = {};
my $foo = $ref;

bless $ref, 'Class';

print blessed($ref) // 'ops';

$foo = "NNN";
print blessed($foo) // 'ops';

=end AN_OBJECT_IS_SIMPLY_A_DATA_STRUCTURE
=cut

=begin A_CLASS_IS_SIMPLY_A_PACKAGE
=end A_CLASS_IS_SIMPLY_A_PACKAGE
=cut
package File;
use Scalar::Util 'blessed';

sub new{
    my $class = shift;
    return bless {}, $class;
}
my $f = File->new();
#my $f = 'File'->new();
print blessed($f) // 'ops';
print @File::ISA;

=begin A_METHOD_IS_SIMPLY_A_SUBROUTINE
=end A_METHOD_IS_SIMPLY_A_SUBROUTINE
=cut

