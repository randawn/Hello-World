#!/usr/bin/perl
use warnings;
use strict;

use Inline::Files;

my %dct;
while(<INPUT>) {
    chomp;
    next unless $_;
    my ($city, $country) = split /,/;
    push @{$dct{$country}}, $city;      # autovivification
}

foreach my $country (sort keys %dct) {
    print $country . ':' . join(', ', sort(@{$dct{$country}})) . "\n";
}

<<GOLDEN;
    Finland: Helsinki.
    Germany: Berlin, Frankfurt.
    USA:  Chicago, New York, Washington.
GOLDEN

__INPUT__
Chicago, USA
Frankfurt, Germany
Berlin, Germany
Washington, USA
Helsinki, Finland
New York, USA
