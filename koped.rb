{\rtf1\ansi\ansicpg1252\cocoartf1671\cocoasubrtf600
{\fonttbl\f0\fmodern\fcharset0 Courier;}
{\colortbl;\red255\green255\blue255;\red0\green0\blue0;}
{\*\expandedcolortbl;;\cssrgb\c0\c0\c0;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720\partightenfactor0

\f0\fs26 \cf0 \expnd0\expndtw0\kerning0
require 'formula'\
\
class Sshpass < Formula\
  url 'http://sourceforge.net/projects/sshpass/files/sshpass/1.06/sshpass-1.06.tar.gz'\
  homepage 'http://sourceforge.net/projects/sshpass'\
  sha256 'c6324fcee608b99a58f9870157dfa754837f8c48be3df0f5e2f3accf145dee60'\
\
  def install\
    system "./configure", "--disable-debug", "--disable-dependency-tracking",\
                          "--prefix=#\{prefix\}"\
    system "make install"\
  end\
\
  def test\
    system "sshpass"\
  end\
end}