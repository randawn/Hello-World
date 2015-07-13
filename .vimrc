set nocompatible
"filetype off

set rtp+=~/.vim/bundle/Vundle.vim
"call vundle#begin()
"Plugin 'gmarik/Vundle'
"Plugin 'scrooloose/syntastic'
"Plugin 'nvie/vim-flake8'
"Plugin 'SirVer/UltiSnips'
"Plugin 'honza/vim-snippets'
"Plugin 'Valloric/YouCompleteMe'
"Plugin 'majutsushi/tagbar'
"call vundle#end()

"filetype on
"filetype plugin indent on
"syntax on

" from vi to vim 
set showcmd        " Show (partial) command in status line.
set showmatch      " Show matching brackets.
set ignorecase     " Do case insensitive matching
set smartcase      " Do smart case matching
set incsearch      " Incremental search
set hlsearch
set autowrite      " Automatically save before commands like :next and :make
set hidden         " Hide buffers when they are abandoned
"set mouse=a       " Enable mouse usage (all modes)
set expandtab
set shiftwidth=4
   
set smarttab
set tabstop=4
set nobackup
set nu
set ruler

"colorscheme slate
set background=dark

"jump to the last position when reopening a file
if has("autocmd")
  au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif
endif

nmap <F5> :w:!./%&
set makeprg=cc\ %<.c

" for the plugin
" let g:UltiSnipsExpandTrigger = "<tab>"


" scheme
map <F9> :%!scheme --arg


