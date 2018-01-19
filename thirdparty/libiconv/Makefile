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
# Thirdpary Makefile for libiconv
########################################################################

########################################################################
#
# libiconv defs
#
########################################################################
LIBICONV_MAKEDIR=$(PWD)

LIBICONV_THIRDPARTY = $(LIBICONV_MAKEDIR)/..
LIBICONV_BUILD_HOME = $(LIBICONV_THIRDPARTY)

ifndef LIBICONV_UNAME
LIBICONV_UNAME = $(shell uname)
endif

ifndef LIBICONV_OS
ifneq ($(LIBICONV_UNAME), Darwin)
LIBICONV_OS = linux
else
LIBICONV_OS = macosx
endif
endif

#
# libiconv version
#
LIBICONV_VERSION_MAJOR = 1
LIBICONV_VERSION_MINOR = 15
LIBICONV_VERSION_RELEASE = 

LIBICONV_VERSION_SEPARATOR = .
LIBICONV_VERSION_MAJOR_SEPARATOR = $(LIBICONV_VERSION_SEPARATOR)
LIBICONV_VERSION_MINOR_SEPARATOR = 

LIBICONV_VERSION_SHORT = $(LIBICONV_VERSION_MAJOR)$(LIBICONV_VERSION_MINOR)$(LIBICONV_VERSION_RELEASE)
LIBICONV_VERSION = $(LIBICONV_VERSION_MAJOR)$(LIBICONV_VERSION_MAJOR_SEPARATOR)$(LIBICONV_VERSION_MINOR)$(LIBICONV_VERSION_MINOR_SEPARATOR)$(LIBICONV_VERSION_RELEASE)

#
# libiconv name
#
LIBICONV_NAME_SEPARATOR = -
LIBICONV_NAME_BASE = libiconv
LIBICONV_NAME = $(LIBICONV_NAME_BASE)$(LIBICONV_NAME_SEPARATOR)$(LIBICONV_VERSION)
LIBICONV_INSTALL_NAME_SEPARATOR = -
LIBICONV_INSTALL_NAME = $(LIBICONV_NAME_BASE)$(LIBICONV_INSTALL_NAME_SEPARATOR)$(LIBICONV_VERSION)
LIBICONV_DIR = $(LIBICONV_NAME)

#
# libiconv archive
#
LIBICONV_ARCHIVED = tar
LIBICONV_COMPRESSED = gz
LIBICONV_ARCHIVE_SEPARATOR = .
LIBICONV_ARCHIVED_SEPARATOR = $(LIBICONV_ARCHIVE_SEPARATOR)
LIBICONV_COMPRESSED_SEPARATOR = $(LIBICONV_ARCHIVE_SEPARATOR)

LIBICONV_EXTRACT_DIR = $(LIBICONV_NAME)
LIBICONV_TGZ_PREFIX = 
LIBICONV_TGZ = $(LIBICONV_NAME)$(LIBICONV_TGZ_PREFIX)$(LIBICONV_ARCHIVED_SEPARATOR)$(LIBICONV_ARCHIVED)$(LIBICONV_COMPRESSED_SEPARATOR)$(LIBICONV_COMPRESSED)
LIBICONV_PATCH_TGZ_PREFIX = $(LIBICONV_NAME_SEPARATOR)patch
LIBICONV_PATCH_TGZ = $(LIBICONV_NAME)$(LIBICONV_PATCH_TGZ_PREFIX)$(LIBICONV_ARCHIVED_SEPARATOR)$(LIBICONV_ARCHIVED)$(LIBICONV_COMPRESSED_SEPARATOR)$(LIBICONV_COMPRESSED)
LIBICONV_DOCS_TGZ_PREFIX = $(LIBICONV_NAME_SEPARATOR)docs
LIBICONV_DOCS_TGZ = $(LIBICONV_NAME)$(LIBICONV_DOCS_TGZ_PREFIX)$(LIBICONV_ARCHIVED_SEPARATOR)$(LIBICONV_ARCHIVED)$(LIBICONV_COMPRESSED_SEPARATOR)$(LIBICONV_COMPRESSED)

#
# libiconv extract
#
ifeq ($(LIBICONV_ARCHIVED),tar)
ifeq ($(LIBICONV_COMPRESSED),gz)
LIBICONV_TAR_UNCOMPRESS = z
LIBICONV_TAR_COMPRESS = z
else
ifeq ($(LIBICONV_COMPRESSED),bz2)
LIBICONV_TAR_UNCOMPRESS = j
LIBICONV_TAR_COMPRESS = j
else
ifeq ($(LIBICONV_COMPRESSED),xz)
LIBICONV_TAR_UNCOMPRESS = J
LIBICONV_TAR_COMPRESS = J
else
endif
endif
endif
LIBICONV_LIST = tar -tv$(LIBICONV_TAR_UNCOMPRESS)f
LIBICONV_EXTRACT = tar -x$(LIBICONV_TAR_UNCOMPRESS)f
LIBICONV_ARCHIVE = tar -cv$(LIBICONV_TAR_COMPRESS)f
else
ifeq ($(LIBICONV_ARCHIVED),zip)
LIBICONV_LIST = unzip -l
LIBICONV_EXTRACT = unzip
LIBICONV_ARCHIVE = zip
else
LIBICONV_LIST = echo unable to list
LIBICONV_EXTRACT = echo unable to extract
LIBICONV_ARCHIVE = echo unable to archive
endif
endif

LIBICONV_LIST_TGZ = $(LIBICONV_LIST) $(LIBICONV_TGZ)
LIBICONV_EXTRACT_TGZ = $(LIBICONV_EXTRACT) $(LIBICONV_TGZ)
LIBICONV_TOUCH_EXTRACT = touch $(LIBICONV_DIR)
LIBICONV_REMOVE_DIR = $(LIBICONV_REMOVE) $(LIBICONV_DIR)

LIBICONV_LIST_PATCH = $(LIBICONV_LIST)
LIBICONV_EXTRACT_PATCH = $(LIBICONV_EXTRACT)
LIBICONV_LIST_PATCH_TGZ = $(LIBICONV_LIST_PATCH) $(LIBICONV_PATCH_TGZ)
LIBICONV_EXTRACT_PATCH_TGZ = $(LIBICONV_EXTRACT_PATCH) $(LIBICONV_PATCH_TGZ)

LIBICONV_LIST_DOCS = $(LIBICONV_LIST)
LIBICONV_EXTRACT_DOCS = $(LIBICONV_EXTRACT)
LIBICONV_LIST_DOCS_TGZ = $(LIBICONV_LIST_DOCS) $(LIBICONV_DOCS_TGZ)
LIBICONV_EXTRACT_DOCS_TGZ = $(LIBICONV_EXTRACT_DOCS) $(LIBICONV_DOCS_TGZ) -C$(LIBICONV_DOCS_PREFIX)

#
# libiconv build
#
ifndef LIBICONV_BUILD_HOME
LIBICONV_BUILD = $(HOME)/build
else
LIBICONV_BUILD = $(LIBICONV_BUILD_HOME)/build
endif
LIBICONV_PREFIX = $(LIBICONV_BUILD)/$(LIBICONV_INSTALL_NAME)
LIBICONV_EXEC_PREFIX = $(LIBICONV_PREFIX)
LIBICONV_CONF_PREFIX = $(LIBICONV_PREFIX)
LIBICONV_DOCS_PREFIX = $(LIBICONV_PREFIX)
LIBICONV_LINK_NAME = $(LIBICONV_BUILD)/$(LIBICONV_NAME_BASE)

LIBICONV_MKDIR = mkdir -p
LIBICONV_REMOVE = rm -r -f

LIBICONV_MAKE_DIR = $(LIBICONV_DIR)
LIBICONV_MAKE_PUSHD = pushd $(LIBICONV_MAKE_DIR)
LIBICONV_MAKE = make

#
# libiconv configure
#
ifneq ($(LIBICONV_UNAME), Darwin)
LIBICONV_CONFIGURE_UNAME = 
else
LIBICONV_CONFIGURE_UNAME = 
endif
LIBICONV_CONFIGURE_CONFIGURE = ./configure
LIBICONV_CONFIGURE_HELP = $(LIBICONV_CONFIGURE_CONFIGURE) --help
LIBICONV_CONFIGURE_PUSHD = pushd $(LIBICONV_MAKE_DIR)

LIBICONV_CONFIGURE = $(LIBICONV_CONFIGURE_CONFIGURE) \
$(LIBICONV_CONFIGURE_UNAME) --enable-static --disable-shared \
--prefix=$(LIBICONV_PREFIX) --exec_prefix=$(LIBICONV_EXEC_PREFIX)

#
# libiconv help
#
LIBICONV_HELP = $(LIBICONV_CONFIGURE_HELP)

########################################################################
#
# rules
#
########################################################################

all: build

again: unextract build

test: test-libiconv

install-links: install-libiconv-links

install-docs: install-libiconv-docs

install-prefix: install-libiconv-prefix

install: install-libiconv

build: build-libiconv

clean: clean-libiconv

configed: configed-$(LIBICONV_DIR)

config: config-$(LIBICONV_DIR)

help: help-libiconv

list-docs: list-libiconv-docs

list-patch: list-libiconv-patch

extract-patch: extract-libiconv-patch

list: list-libiconv

extract: extract-libiconv

unextract: unextract-libiconv

archive: archive-libiconv

linked: libiconv-linked

prefixed: libiconv-prefixed

archived: libiconv-archived

extracted: libiconv-extracted

########################################################################
#
# libiconv rules
#
########################################################################

#
# Help libiconv
#
help-libiconv: $(LIBICONV_DIR)
	@($(LIBICONV_CONFIGURE_PUSHD);\
	  (($(LIBICONV_HELP)) || (exit 1));\
	  popd)

#
# Install libiconv
#
install-libiconv: configed-$(LIBICONV_DIR)
	@(echo Installing $(LIBICONV_DIR)...;\
	  $(LIBICONV_MAKE_PUSHD);\
	  (($(LIBICONV_MAKE) install) || (exit 1)) && \
	  ((touch $(LIBICONV_MAKEDIR)/configed-$(LIBICONV_DIR)) || (exit 1));\
	  popd)
	  
#
# Build libiconv
#
build-libiconv: configed-$(LIBICONV_DIR)
	@(echo Building $(LIBICONV_DIR)...;\
	  $(LIBICONV_MAKE_PUSHD);\
	  (($(LIBICONV_MAKE)) || (exit 1)) && \
	  ((touch $(LIBICONV_MAKEDIR)/configed-$(LIBICONV_DIR)) || (exit 1));\
	  popd)
	  
#
# Clean libiconv
#
clean-libiconv: configed-$(LIBICONV_DIR)
	@(echo Cleaning $(LIBICONV_DIR)...;\
	  $(LIBICONV_MAKE_PUSHD);\
	  (($(LIBICONV_MAKE) clean) || (exit 1)) && \
	  ((touch $(LIBICONV_MAKEDIR)/configed-$(LIBICONV_DIR)) || (exit 1));\
	  popd)
	  
#
# Test libiconv
#
test-libiconv: configed-$(LIBICONV_DIR)
	@(echo Building test $(LIBICONV_DIR)...;\
	  $(LIBICONV_MAKE_PUSHD);\
	  (($(LIBICONV_MAKE) test) || (exit 1)) && \
	  ((touch $(LIBICONV_MAKEDIR)/configed-$(LIBICONV_DIR)) || (exit 1));\
	  popd)
	  
#
# Config libiconv
#
config-$(LIBICONV_DIR): unconfig-$(LIBICONV_DIR) configed-$(LIBICONV_DIR)

unconfig-$(LIBICONV_DIR):
	@(rm -f configed-$(LIBICONV_DIR))

configed-$(LIBICONV_DIR): $(LIBICONV_DIR)
	@(echo Configing $(LIBICONV_DIR)...;\
	  $(LIBICONV_CONFIGURE_PUSHD);\
	  (($(LIBICONV_CONFIGURE)) || (exit 1)) && \
	  ((touch $(LIBICONV_DIR)) || (exit 1)) && \
	  ((touch $(LIBICONV_MAKEDIR)/configed-$(LIBICONV_DIR)) || (exit 1));\
	  popd)

########################################################################
# docs
########################################################################

#
# List libiconv Docs
#
list-libiconv-docs: $(LIBICONV_DOCS_TGZ)
	@(echo Listing $(LIBICONV_DOCS_TGZ)...;\
	  (($(LIBICONV_LIST_DOCS_TGZ)) || (exit 1)))

#
# Install libiconv Docs
#
install-libiconv-docs: $(LIBICONV_DOCS_PREFIX)
	@(echo Extracting $(LIBICONV_DOCS_TGZ)...;\
	  (($(LIBICONV_EXTRACT_DOCS_TGZ)) || (exit 1)))

########################################################################
# patch
########################################################################

#
# List libiconv Patch
#
list-libiconv-patch: $(LIBICONV_PATCH_TGZ)
	@(echo Listing $(LIBICONV_PATCH_TGZ)...;\
	  (($(LIBICONV_LIST_PATCH_TGZ)) || (exit 1)))

#
# Extract libiconv patch
#
extract-libiconv-patch: $(LIBICONV_DIR)
	@(echo Extracting $(LIBICONV_PATCH_TGZ)...;\
	  (($(LIBICONV_EXTRACT_PATCH_TGZ)) || (exit 1)))

########################################################################
# archive
########################################################################

#
# List libiconv
#
list-libiconv: 
	@(echo Listing $(LIBICONV_TGZ)...;\
	  (($(LIBICONV_LIST_TGZ)) || (exit 1)))

#
# libiconv extracted
#
libiconv-extracted: 
	@(echo $(LIBICONV_EXTRACT) $(LIBICONV_TGZ))

#
# Extract libiconv
#
extract-libiconv: unextract-libiconv $(LIBICONV_DIR)

unextract-libiconv: unconfig-$(LIBICONV_DIR)
	@(echo Removing $(LIBICONV_DIR)...;\
	  (($(LIBICONV_REMOVE_DIR)) || (exit 1)))

$(LIBICONV_DIR): $(LIBICONV_TGZ)
	@(echo Extracting $(LIBICONV_TGZ)...;\
	  (($(LIBICONV_EXTRACT_TGZ)) || (exit 1)) && \
	  (($(LIBICONV_TOUCH_EXTRACT)) || (exit 1)))
	  
#
# libiconv archived
#
libiconv-archived: 
	@(echo $(LIBICONV_TGZ))
	  
#
# Archive libiconv
#
archive-libiconv: 
	@(echo Archiving $(LIBICONV_DIR) to $(LIBICONV_TGZ)...;\
	  (($(LIBICONV_ARCHIVE) $(LIBICONV_TGZ) $(LIBICONV_DIR)) || (exit 1)))

########################################################################
# links
########################################################################

#
# libiconv linked
#
libiconv-linked: 
	@echo link is $(LIBICONV_LINK_NAME) "->" $(LIBICONV_PREFIX)
	  
#
# Install libiconv links
#
install-libiconv-links: 
	@((echo removing $(LIBICONV_LINK_NAME)) && \
	  ((rm -f $(LIBICONV_LINK_NAME)) || (exit 1)) && \
	  (echo Linking $(LIBICONV_LINK_NAME) "->" $(LIBICONV_PREFIX)) && \
	  ((ln -s $(LIBICONV_PREFIX) $(LIBICONV_LINK_NAME)) || (exit 1)))
	  
########################################################################
# prefix
########################################################################

#
# libiconv prefixed
#
libiconv-prefixed: 
	@((echo prefix is $(LIBICONV_PREFIX)) && \
	  (echo exec prefix is $(LIBICONV_EXEC_PREFIX)) && \
	  (echo conf prefix is $(LIBICONV_CONF_PREFIX)) && \
	  (echo docs prefix is $(LIBICONV_DOCS_PREFIX)))
	  
#
# Install libiconv prefix
#
install-libiconv-prefix: 
	@((echo makeing $(LIBICONV_PREFIX)) && \
	  ((mkdir -p $(LIBICONV_PREFIX)) || (exit 1)) && \
	  (echo makeing $(LIBICONV_EXEC_PREFIX)) && \
	  ((mkdir -p $(LIBICONV_EXEC_PREFIX)) || (exit 1)))
	  
$(LIBICONV_PREFIX):
	@(echo Makeing Directory $(LIBICONV_PREFIX)...;\
	  (($(LIBICONV_MKDIR) $(LIBICONV_PREFIX)) || (exit 1)))

$(LIBICONV_EXEC_PREFIX):
	@(echo Makeing Directory $(LIBICONV_EXEC_PREFIX)...;\
	  (($(LIBICONV_MKDIR) $(LIBICONV_EXEC_PREFIX)) || (exit 1)))

$(LIBICONV_CONF_PREFIX):
	@(echo Makeing Directory $(LIBICONV_CONF_PREFIX)...;\
	  (($(LIBICONV_MKDIR) $(LIBICONV_CONF_PREFIX)) || (exit 1)))

$(LIBICONV_DOCS_PREFIX):
	@(echo Makeing Directory $(LIBICONV_DOCS_PREFIX)...;\
	  (($(LIBICONV_MKDIR) $(LIBICONV_DOCS_PREFIX)) || (exit 1)))




        

