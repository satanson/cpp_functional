#!/usr/bin/perl -w
use strict;
use Getopt::Std;
our ($opt_g,$opt_s);
getopts('gs') or die "invalid argument";
my $SRC=join " ",map{m#(?:.*/)?(\w*\.cpp)\z#;$1} grep {m#\.cpp\z#}@ARGV;
my ($dbg,$silent)=("")x2;
$dbg="dbg=1" if $opt_g;
$silent=1 if $opt_s;
print $SRC,"\n";

for my $src (split /\s+/,$SRC){
	print qq(make $dbg -B SRC="$src"),"\n";
	my $rc=system qq(make $dbg -B SRC="$src") if -s "src/$src" or -s "demos/$src";

	if (!$rc && !$silent){
		my $bin=$src=~s/(.*)\.cpp/$1/r;
		print "\n" x 2 . "-" x 10 ." exec $bin " . "-" x 10 . "\n" x 2;
		system qq(bin/$bin);
	}
}
