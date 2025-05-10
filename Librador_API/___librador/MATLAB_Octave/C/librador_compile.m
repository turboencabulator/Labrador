function [] = librador_compile(fname_no_dot_cpp, idename)
  fprintf("\n\n\nCompiling %s.cpp...\n\n\n", fname_no_dot_cpp);
  fflush(stdout);
  mex(['-DCOMPILE_FOR_' idename], '-I../../../Desktop_Interface/build_linux/libusb', '-I../librador', '-lrador', '-L../librador', '-Wl,-rpath=../librador', ['C/mexsrc/' fname_no_dot_cpp '.cpp'])
  copyfile([fname_no_dot_cpp '.mex'], 'C/mex_outputs')
  delete([fname_no_dot_cpp '.mex'])
  copyfile([fname_no_dot_cpp '.o'], 'C/mex_outputs')
  delete([fname_no_dot_cpp '.o'])
return;
