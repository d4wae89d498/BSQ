# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    map_generator.pl                                 .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mfaussur <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/08/19 13:28:28 by mfaussur     #+#   ##    ##    #+#        #
#    Updated: 2019/08/19 13:28:53 by mfaussur    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

#!/usr/bin/perl

use warnings;
use strict;
die "program x y density" unless (scalar(@ARGV) == 3);
my ($x, $y, $density) = @ARGV;
print "$y.ox\n";
for (my $i = 0; $i < $y; $i++) {
	for (my $j = 0; $j < $x; $j++) {
		if (int(rand($y) * 2) < $density) {
					   print "o";
				   }
				   else {
					   print "."; }
		}
		print "\n";
}
