########################################################################
# Copyright (c) 1988-2018 $organization$
#
# This software is provided by the author and contributors ``as is'' 
# and any express or implied warranties, including, but not limited to, 
# the implied warranties of merchantability and fitness for a particular 
# purpose are disclaimed. In no event shall the author or contributors 
# be liable for any direct, indirect, incidental, special, exemplary, 
# or consequential damages (including, but not limited to, procurement 
# of substitute goods or services; loss of use, data, or profits; or 
# business interruption) however caused and on any theory of liability, 
# whether in contract, strict liability, or tort (including negligence 
# or otherwise) arising in any way out of the use of this software, 
# even if advised of the possibility of such damage.
#
#   File: Makefile
#
# Author: $author$
#   Date: 1/13/2018
#
# Thirdpary Makefile for unixODBC
########################################################################

########################################################################
#
# unixODBC defs
#
########################################################################
UNIXODBC_MAKEDIR=$(PWD)

UNIXODBC_THIRDPARTY = $(UNIXODBC_MAKEDIR)/..
UNIXODBC_BUILD_HOME = $(UNIXODBC_THIRDPARTY)

ifndef UNIXODBC_UNAME
UNIXODBC_UNAME = $(shell uname)
endif

ifndef UNIXODBC_OS
ifneq ($(UNIXODBC_UNAME), Darwin)
UNIXODBC_OS = linux
else
UNIXODBC_OS = macosx
endif
endif

#
# unixODBC version
#
UNIXODBC_VERSION_MAJOR = 2
UNIXODBC_VERSION_MINOR = 3
UNIXODBC_VERSION_RELEASE = 4

UNIXODBC_VERSION_SEPARATOR = .
UNIXODBC_VERSION_MAJOR_SEPARATOR = $(UNIXODBC_VERSION_SEPARATOR)
UNIXODBC_VERSION_MINOR_SEPARATOR = $(UNIXODBC_VERSION_SEPARATOR)

UNIXODBC_VERSION_SHORT = $(UNIXODBC_VERSION_MAJOR)$(UNIXODBC_VERSION_MINOR)$(UNIXODBC_VERSION_RELEASE)
UNIXODBC_VERSION = $(UNIXODBC_VERSION_MAJOR)$(UNIXODBC_VERSION_MAJOR_SEPARATOR)$(UNIXODBC_VERSION_MINOR)$(UNIXODBC_VERSION_MINOR_SEPARATOR)$(UNIXODBC_VERSION_RELEASE)

#
# unixODBC name
#
UNIXODBC_NAME_SEPARATOR = -
UNIXODBC_NAME_BASE = unixODBC
UNIXODBC_NAME = $(UNIXODBC_NAME_BASE)$(UNIXODBC_NAME_SEPARATOR)$(UNIXODBC_VERSION)
UNIXODBC_INSTALL_NAME_SEPARATOR = -
UNIXODBC_INSTALL_NAME = $(UNIXODBC_NAME_BASE)$(UNIXODBC_INSTALL_NAME_SEPARATOR)$(UNIXODBC_VERSION)
UNIXODBC_DIR = $(UNIXODBC_NAME)

#
# unixODBC archive
#
UNIXODBC_ARCHIVED = tar
UNIXODBC_COMPRESSED = gz
UNIXODBC_ARCHIVE_SEPARATOR = .
UNIXODBC_ARCHIVED_SEPARATOR = $(UNIXODBC_ARCHIVE_SEPARATOR)
UNIXODBC_COMPRESSED_SEPARATOR = $(UNIXODBC_ARCHIVE_SEPARATOR)

UNIXODBC_EXTRACT_DIR = $(UNIXODBC_NAME)
UNIXODBC_TGZ_PREFIX = 
UNIXODBC_TGZ = $(UNIXODBC_NAME)$(UNIXODBC_TGZ_PREFIX)$(UNIXODBC_ARCHIVED_SEPARATOR)$(UNIXODBC_ARCHIVED)$(UNIXODBC_COMPRESSED_SEPARATOR)$(UNIXODBC_COMPRESSED)
UNIXODBC_PATCH_TGZ_PREFIX = $(UNIXODBC_NAME_SEPARATOR)patch
UNIXODBC_PATCH_TGZ = $(UNIXODBC_NAME)$(UNIXODBC_PATCH_TGZ_PREFIX)$(UNIXODBC_ARCHIVED_SEPARATOR)$(UNIXODBC_ARCHIVED)$(UNIXODBC_COMPRESSED_SEPARATOR)$(UNIXODBC_COMPRESSED)
UNIXODBC_DOCS_TGZ_PREFIX = $(UNIXODBC_NAME_SEPARATOR)docs
UNIXODBC_DOCS_TGZ = $(UNIXODBC_NAME)$(UNIXODBC_DOCS_TGZ_PREFIX)$(UNIXODBC_ARCHIVED_SEPARATOR)$(UNIXODBC_ARCHIVED)$(UNIXODBC_COMPRESSED_SEPARATOR)$(UNIXODBC_COMPRESSED)

#
# unixODBC extract
#
ifeq ($(UNIXODBC_ARCHIVED),tar)
ifeq ($(UNIXODBC_COMPRESSED),gz)
UNIXODBC_TAR_UNCOMPRESS = z
UNIXODBC_TAR_COMPRESS = z
else
ifeq ($(UNIXODBC_COMPRESSED),bz2)
UNIXODBC_TAR_UNCOMPRESS = j
UNIXODBC_TAR_COMPRESS = j
else
ifeq ($(UNIXODBC_COMPRESSED),xz)
UNIXODBC_TAR_UNCOMPRESS = J
UNIXODBC_TAR_COMPRESS = J
else
endif
endif
endif
UNIXODBC_LIST = tar -tv$(UNIXODBC_TAR_UNCOMPRESS)f
UNIXODBC_EXTRACT = tar -x$(UNIXODBC_TAR_UNCOMPRESS)f
UNIXODBC_ARCHIVE = tar -cv$(UNIXODBC_TAR_COMPRESS)f
else
ifeq ($(UNIXODBC_ARCHIVED),zip)
UNIXODBC_LIST = unzip -l
UNIXODBC_EXTRACT = unzip
UNIXODBC_ARCHIVE = zip
else
UNIXODBC_LIST = echo unable to list
UNIXODBC_EXTRACT = echo unable to extract
UNIXODBC_ARCHIVE = echo unable to archive
endif
endif

UNIXODBC_LIST_TGZ = $(UNIXODBC_LIST) $(UNIXODBC_TGZ)
UNIXODBC_EXTRACT_TGZ = $(UNIXODBC_EXTRACT) $(UNIXODBC_TGZ)
UNIXODBC_TOUCH_EXTRACT = touch $(UNIXODBC_DIR)
UNIXODBC_REMOVE_DIR = $(UNIXODBC_REMOVE) $(UNIXODBC_DIR)

UNIXODBC_LIST_PATCH = $(UNIXODBC_LIST)
UNIXODBC_EXTRACT_PATCH = $(UNIXODBC_EXTRACT)
UNIXODBC_LIST_PATCH_TGZ = $(UNIXODBC_LIST_PATCH) $(UNIXODBC_PATCH_TGZ)
UNIXODBC_EXTRACT_PATCH_TGZ = $(UNIXODBC_EXTRACT_PATCH) $(UNIXODBC_PATCH_TGZ)

UNIXODBC_LIST_DOCS = $(UNIXODBC_LIST)
UNIXODBC_EXTRACT_DOCS = $(UNIXODBC_EXTRACT)
UNIXODBC_LIST_DOCS_TGZ = $(UNIXODBC_LIST_DOCS) $(UNIXODBC_DOCS_TGZ)
UNIXODBC_EXTRACT_DOCS_TGZ = $(UNIXODBC_EXTRACT_DOCS) $(UNIXODBC_DOCS_TGZ) -C$(UNIXODBC_DOCS_PREFIX)

#
# unixODBC build
#
ifndef UNIXODBC_BUILD_HOME
UNIXODBC_BUILD = $(HOME)/build
else
UNIXODBC_BUILD = $(UNIXODBC_BUILD_HOME)/build
endif
UNIXODBC_PREFIX = $(UNIXODBC_BUILD)/$(UNIXODBC_INSTALL_NAME)
UNIXODBC_EXEC_PREFIX = $(UNIXODBC_PREFIX)
UNIXODBC_CONF_PREFIX = $(UNIXODBC_PREFIX)
UNIXODBC_DOCS_PREFIX = $(UNIXODBC_PREFIX)
UNIXODBC_LINK_NAME = $(UNIXODBC_BUILD)/$(UNIXODBC_NAME_BASE)

UNIXODBC_MKDIR = mkdir -p
UNIXODBC_REMOVE = rm -r -f

UNIXODBC_MAKE_DIR = $(UNIXODBC_DIR)
UNIXODBC_MAKE_PUSHD = pushd $(UNIXODBC_MAKE_DIR)
UNIXODBC_MAKE = make

#
# unixODBC configure
#
ifneq ($(UNIXODBC_UNAME), Darwin)
UNIXODBC_CONFIGURE_UNAME = 
else
UNIXODBC_CONFIGURE_UNAME = 
endif
UNIXODBC_CONFIGURE_CONFIGURE = ./configure
UNIXODBC_CONFIGURE_HELP = $(UNIXODBC_CONFIGURE_CONFIGURE) --help
UNIXODBC_CONFIGURE_PUSHD = pushd $(UNIXODBC_MAKE_DIR)

UNIXODBC_CONFIGURE = $(UNIXODBC_CONFIGURE_CONFIGURE) \
$(UNIXODBC_CONFIGURE_UNAME) \
--enable-static --disable-shared \
--with-libiconv-prefix=$(UNIXODBC_THIRDPARTY)/build/libiconv \
--prefix=$(UNIXODBC_PREFIX) --exec_prefix=$(UNIXODBC_EXEC_PREFIX)

#
# unixODBC help
#
UNIXODBC_HELP = $(UNIXODBC_CONFIGURE_HELP)

########################################################################
#
# rules
#
########################################################################

all: build

again: unextract build

test: test-unixodbc

install-links: install-unixodbc-links

install-docs: install-unixodbc-docs

install-prefix: install-unixodbc-prefix

install: install-unixodbc

build: build-unixodbc

clean: clean-unixodbc

configed: configed-$(UNIXODBC_DIR)

config: config-$(UNIXODBC_DIR)

help: help-unixodbc

list-docs: list-unixodbc-docs

list-patch: list-unixodbc-patch

extract-patch: extract-unixodbc-patch

list: list-unixodbc

extract: extract-unixodbc

unextract: unextract-unixodbc

archive: archive-unixodbc

linked: unixodbc-linked

prefixed: unixodbc-prefixed

archived: unixodbc-archived

extracted: unixodbc-extracted

########################################################################
#
# unixODBC rules
#
########################################################################

#
# Help unixODBC
#
help-unixodbc: $(UNIXODBC_DIR)
	@($(UNIXODBC_CONFIGURE_PUSHD);\
	  (($(UNIXODBC_HELP)) || (exit 1));\
	  popd)

#
# Install unixODBC
#
install-unixodbc: configed-$(UNIXODBC_DIR)
	@(echo Installing $(UNIXODBC_DIR)...;\
	  $(UNIXODBC_MAKE_PUSHD);\
	  (($(UNIXODBC_MAKE) install) || (exit 1)) && \
	  ((touch $(UNIXODBC_MAKEDIR)/configed-$(UNIXODBC_DIR)) || (exit 1));\
	  popd)
	  
#
# Build unixODBC
#
build-unixodbc: configed-$(UNIXODBC_DIR)
	@(echo Building $(UNIXODBC_DIR)...;\
	  $(UNIXODBC_MAKE_PUSHD);\
	  (($(UNIXODBC_MAKE)) || (exit 1)) && \
	  ((touch $(UNIXODBC_MAKEDIR)/configed-$(UNIXODBC_DIR)) || (exit 1));\
	  popd)
	  
#
# Clean unixODBC
#
clean-unixodbc: configed-$(UNIXODBC_DIR)
	@(echo Cleaning $(UNIXODBC_DIR)...;\
	  $(UNIXODBC_MAKE_PUSHD);\
	  (($(UNIXODBC_MAKE) clean) || (exit 1)) && \
	  ((touch $(UNIXODBC_MAKEDIR)/configed-$(UNIXODBC_DIR)) || (exit 1));\
	  popd)
	  
#
# Test unixODBC
#
test-unixodbc: configed-$(UNIXODBC_DIR)
	@(echo Building test $(UNIXODBC_DIR)...;\
	  $(UNIXODBC_MAKE_PUSHD);\
	  (($(UNIXODBC_MAKE) test) || (exit 1)) && \
	  ((touch $(UNIXODBC_MAKEDIR)/configed-$(UNIXODBC_DIR)) || (exit 1));\
	  popd)
	  
#
# Config unixODBC
#
config-$(UNIXODBC_DIR): unconfig-$(UNIXODBC_DIR) configed-$(UNIXODBC_DIR)

unconfig-$(UNIXODBC_DIR):
	@(rm -f configed-$(UNIXODBC_DIR))

configed-$(UNIXODBC_DIR): $(UNIXODBC_DIR)
	@(echo Configing $(UNIXODBC_DIR)...;\
	  $(UNIXODBC_CONFIGURE_PUSHD);\
	  (($(UNIXODBC_CONFIGURE)) || (exit 1)) && \
	  ((touch $(UNIXODBC_DIR)) || (exit 1)) && \
	  ((touch $(UNIXODBC_MAKEDIR)/configed-$(UNIXODBC_DIR)) || (exit 1));\
	  popd)

########################################################################
# docs
########################################################################

#
# List unixODBC Docs
#
list-unixodbc-docs: $(UNIXODBC_DOCS_TGZ)
	@(echo Listing $(UNIXODBC_DOCS_TGZ)...;\
	  (($(UNIXODBC_LIST_DOCS_TGZ)) || (exit 1)))

#
# Install unixODBC Docs
#
install-unixodbc-docs: $(UNIXODBC_DOCS_PREFIX)
	@(echo Extracting $(UNIXODBC_DOCS_TGZ)...;\
	  (($(UNIXODBC_EXTRACT_DOCS_TGZ)) || (exit 1)))

########################################################################
# patch
########################################################################

#
# List unixODBC Patch
#
list-unixodbc-patch: $(UNIXODBC_PATCH_TGZ)
	@(echo Listing $(UNIXODBC_PATCH_TGZ)...;\
	  (($(UNIXODBC_LIST_PATCH_TGZ)) || (exit 1)))

#
# Extract unixODBC patch
#
extract-unixodbc-patch: $(UNIXODBC_DIR)
	@(echo Extracting $(UNIXODBC_PATCH_TGZ)...;\
	  (($(UNIXODBC_EXTRACT_PATCH_TGZ)) || (exit 1)))

########################################################################
# archive
########################################################################

#
# List unixODBC
#
list-unixodbc: 
	@(echo Listing $(UNIXODBC_TGZ)...;\
	  (($(UNIXODBC_LIST_TGZ)) || (exit 1)))

#
# unixODBC extracted
#
unixodbc-extracted: 
	@(echo $(UNIXODBC_EXTRACT) $(UNIXODBC_TGZ))

#
# Extract unixODBC
#
extract-unixodbc: unextract-unixodbc $(UNIXODBC_DIR)

unextract-unixodbc: unconfig-$(UNIXODBC_DIR)
	@(echo Removing $(UNIXODBC_DIR)...;\
	  (($(UNIXODBC_REMOVE_DIR)) || (exit 1)))

$(UNIXODBC_DIR): $(UNIXODBC_TGZ)
	@(echo Extracting $(UNIXODBC_TGZ)...;\
	  (($(UNIXODBC_EXTRACT_TGZ)) || (exit 1)) && \
	  (($(UNIXODBC_TOUCH_EXTRACT)) || (exit 1)))
	  
#
# unixODBC archived
#
unixodbc-archived: 
	@(echo $(UNIXODBC_TGZ))
	  
#
# Archive unixODBC
#
archive-unixodbc: 
	@(echo Archiving $(UNIXODBC_DIR) to $(UNIXODBC_TGZ)...;\
	  (($(UNIXODBC_ARCHIVE) $(UNIXODBC_TGZ) $(UNIXODBC_DIR)) || (exit 1)))

########################################################################
# links
########################################################################

#
# unixODBC linked
#
unixodbc-linked: 
	@echo link is $(UNIXODBC_LINK_NAME) "->" $(UNIXODBC_PREFIX)
	  
#
# Install unixODBC links
#
install-unixodbc-links: 
	@((echo removing $(UNIXODBC_LINK_NAME)) && \
	  ((rm -f $(UNIXODBC_LINK_NAME)) || (exit 1)) && \
	  (echo Linking $(UNIXODBC_LINK_NAME) "->" $(UNIXODBC_PREFIX)) && \
	  ((ln -s $(UNIXODBC_PREFIX) $(UNIXODBC_LINK_NAME)) || (exit 1)))
	  
########################################################################
# prefix
########################################################################

#
# unixODBC prefixed
#
unixodbc-prefixed: 
	@((echo prefix is $(UNIXODBC_PREFIX)) && \
	  (echo exec prefix is $(UNIXODBC_EXEC_PREFIX)) && \
	  (echo conf prefix is $(UNIXODBC_CONF_PREFIX)) && \
	  (echo docs prefix is $(UNIXODBC_DOCS_PREFIX)))
	  
#
# Install unixODBC prefix
#
install-unixodbc-prefix: 
	@((echo makeing $(UNIXODBC_PREFIX)) && \
	  ((mkdir -p $(UNIXODBC_PREFIX)) || (exit 1)) && \
	  (echo makeing $(UNIXODBC_EXEC_PREFIX)) && \
	  ((mkdir -p $(UNIXODBC_EXEC_PREFIX)) || (exit 1)))
	  
$(UNIXODBC_PREFIX):
	@(echo Makeing Directory $(UNIXODBC_PREFIX)...;\
	  (($(UNIXODBC_MKDIR) $(UNIXODBC_PREFIX)) || (exit 1)))

$(UNIXODBC_EXEC_PREFIX):
	@(echo Makeing Directory $(UNIXODBC_EXEC_PREFIX)...;\
	  (($(UNIXODBC_MKDIR) $(UNIXODBC_EXEC_PREFIX)) || (exit 1)))

$(UNIXODBC_CONF_PREFIX):
	@(echo Makeing Directory $(UNIXODBC_CONF_PREFIX)...;\
	  (($(UNIXODBC_MKDIR) $(UNIXODBC_CONF_PREFIX)) || (exit 1)))

$(UNIXODBC_DOCS_PREFIX):
	@(echo Makeing Directory $(UNIXODBC_DOCS_PREFIX)...;\
	  (($(UNIXODBC_MKDIR) $(UNIXODBC_DOCS_PREFIX)) || (exit 1)))




        

