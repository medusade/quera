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
# Thirdpary Makefile for freetds
########################################################################

########################################################################
#
# freetds defs
#
########################################################################
FREETDS_MAKEDIR=$(PWD)

FREETDS_THIRDPARTY = $(FREETDS_MAKEDIR)/..
FREETDS_BUILD_HOME = $(FREETDS_THIRDPARTY)

ifndef FREETDS_UNAME
FREETDS_UNAME = $(shell uname)
endif

ifndef FREETDS_OS
ifneq ($(FREETDS_UNAME), Darwin)
FREETDS_OS = linux
else
FREETDS_OS = macosx
endif
endif

#
# freetds version
#
FREETDS_VERSION_MAJOR = 1
FREETDS_VERSION_MINOR = 00
FREETDS_VERSION_RELEASE = 27

FREETDS_VERSION_SEPARATOR = .
FREETDS_VERSION_MAJOR_SEPARATOR = $(FREETDS_VERSION_SEPARATOR)
FREETDS_VERSION_MINOR_SEPARATOR = $(FREETDS_VERSION_SEPARATOR)

FREETDS_VERSION_SHORT = $(FREETDS_VERSION_MAJOR)$(FREETDS_VERSION_MINOR)$(FREETDS_VERSION_RELEASE)
FREETDS_VERSION = $(FREETDS_VERSION_MAJOR)$(FREETDS_VERSION_MAJOR_SEPARATOR)$(FREETDS_VERSION_MINOR)$(FREETDS_VERSION_MINOR_SEPARATOR)$(FREETDS_VERSION_RELEASE)

#
# freetds name
#
FREETDS_NAME_SEPARATOR = -
FREETDS_NAME_BASE = freetds
FREETDS_NAME = $(FREETDS_NAME_BASE)$(FREETDS_NAME_SEPARATOR)$(FREETDS_VERSION)
FREETDS_INSTALL_NAME_SEPARATOR = -
FREETDS_INSTALL_NAME = $(FREETDS_NAME_BASE)$(FREETDS_INSTALL_NAME_SEPARATOR)$(FREETDS_VERSION)
FREETDS_DIR = $(FREETDS_NAME)

#
# freetds archive
#
FREETDS_ARCHIVED = tar
FREETDS_COMPRESSED = gz
FREETDS_ARCHIVE_SEPARATOR = .
FREETDS_ARCHIVED_SEPARATOR = $(FREETDS_ARCHIVE_SEPARATOR)
FREETDS_COMPRESSED_SEPARATOR = $(FREETDS_ARCHIVE_SEPARATOR)

FREETDS_EXTRACT_DIR = $(FREETDS_NAME)
FREETDS_TGZ_PREFIX = 
FREETDS_TGZ = $(FREETDS_NAME)$(FREETDS_TGZ_PREFIX)$(FREETDS_ARCHIVED_SEPARATOR)$(FREETDS_ARCHIVED)$(FREETDS_COMPRESSED_SEPARATOR)$(FREETDS_COMPRESSED)
FREETDS_PATCH_TGZ_PREFIX = $(FREETDS_NAME_SEPARATOR)patch
FREETDS_PATCH_TGZ = $(FREETDS_NAME)$(FREETDS_PATCH_TGZ_PREFIX)$(FREETDS_ARCHIVED_SEPARATOR)$(FREETDS_ARCHIVED)$(FREETDS_COMPRESSED_SEPARATOR)$(FREETDS_COMPRESSED)
FREETDS_DOCS_TGZ_PREFIX = $(FREETDS_NAME_SEPARATOR)docs
FREETDS_DOCS_TGZ = $(FREETDS_NAME)$(FREETDS_DOCS_TGZ_PREFIX)$(FREETDS_ARCHIVED_SEPARATOR)$(FREETDS_ARCHIVED)$(FREETDS_COMPRESSED_SEPARATOR)$(FREETDS_COMPRESSED)

#
# freetds extract
#
ifeq ($(FREETDS_ARCHIVED),tar)
ifeq ($(FREETDS_COMPRESSED),gz)
FREETDS_TAR_UNCOMPRESS = z
FREETDS_TAR_COMPRESS = z
else
ifeq ($(FREETDS_COMPRESSED),bz2)
FREETDS_TAR_UNCOMPRESS = j
FREETDS_TAR_COMPRESS = j
else
ifeq ($(FREETDS_COMPRESSED),xz)
FREETDS_TAR_UNCOMPRESS = J
FREETDS_TAR_COMPRESS = J
else
endif
endif
endif
FREETDS_LIST = tar -tv$(FREETDS_TAR_UNCOMPRESS)f
FREETDS_EXTRACT = tar -x$(FREETDS_TAR_UNCOMPRESS)f
FREETDS_ARCHIVE = tar -cv$(FREETDS_TAR_COMPRESS)f
else
ifeq ($(FREETDS_ARCHIVED),zip)
FREETDS_LIST = unzip -l
FREETDS_EXTRACT = unzip
FREETDS_ARCHIVE = zip
else
FREETDS_LIST = echo unable to list
FREETDS_EXTRACT = echo unable to extract
FREETDS_ARCHIVE = echo unable to archive
endif
endif

FREETDS_LIST_TGZ = $(FREETDS_LIST) $(FREETDS_TGZ)
FREETDS_EXTRACT_TGZ = $(FREETDS_EXTRACT) $(FREETDS_TGZ)
FREETDS_TOUCH_EXTRACT = touch $(FREETDS_DIR)
FREETDS_REMOVE_DIR = $(FREETDS_REMOVE) $(FREETDS_DIR)

FREETDS_LIST_PATCH = $(FREETDS_LIST)
FREETDS_EXTRACT_PATCH = $(FREETDS_EXTRACT)
FREETDS_LIST_PATCH_TGZ = $(FREETDS_LIST_PATCH) $(FREETDS_PATCH_TGZ)
FREETDS_EXTRACT_PATCH_TGZ = $(FREETDS_EXTRACT_PATCH) $(FREETDS_PATCH_TGZ)

FREETDS_LIST_DOCS = $(FREETDS_LIST)
FREETDS_EXTRACT_DOCS = $(FREETDS_EXTRACT)
FREETDS_LIST_DOCS_TGZ = $(FREETDS_LIST_DOCS) $(FREETDS_DOCS_TGZ)
FREETDS_EXTRACT_DOCS_TGZ = $(FREETDS_EXTRACT_DOCS) $(FREETDS_DOCS_TGZ) -C$(FREETDS_DOCS_PREFIX)

#
# freetds build
#
ifndef FREETDS_BUILD_HOME
FREETDS_BUILD = $(HOME)/build
else
FREETDS_BUILD = $(FREETDS_BUILD_HOME)/build
endif
FREETDS_PREFIX = $(FREETDS_BUILD)/$(FREETDS_INSTALL_NAME)
FREETDS_EXEC_PREFIX = $(FREETDS_PREFIX)
FREETDS_CONF_PREFIX = $(FREETDS_PREFIX)
FREETDS_DOCS_PREFIX = $(FREETDS_PREFIX)
FREETDS_LINK_NAME = $(FREETDS_BUILD)/$(FREETDS_NAME_BASE)

FREETDS_MKDIR = mkdir -p
FREETDS_REMOVE = rm -r -f

FREETDS_MAKE_DIR = $(FREETDS_DIR)
FREETDS_MAKE_PUSHD = pushd $(FREETDS_MAKE_DIR)
FREETDS_MAKE = make

#
# freetds configure
#
ifneq ($(FREETDS_UNAME), Darwin)
FREETDS_CONFIGURE_UNAME = 
else
FREETDS_CONFIGURE_UNAME = 
endif
FREETDS_CONFIGURE_CONFIGURE = ./configure
FREETDS_CONFIGURE_HELP = $(FREETDS_CONFIGURE_CONFIGURE) --help
FREETDS_CONFIGURE_PUSHD = pushd $(FREETDS_MAKE_DIR)

FREETDS_CONFIGURE = $(FREETDS_CONFIGURE_CONFIGURE) \
$(FREETDS_CONFIGURE_UNAME) \
--enable-static --enable-shared \
--enable-msdblib --with-unixodbc=$(FREETDS_THIRDPARTY)/build/unixODBC \
--prefix=$(FREETDS_PREFIX) --exec_prefix=$(FREETDS_EXEC_PREFIX)

#--with-libiconv-prefix=$(FREETDS_THIRDPARTY)/build/libiconv \
#
# freetds help
#
FREETDS_HELP = $(FREETDS_CONFIGURE_HELP)

########################################################################
#
# rules
#
########################################################################

all: build

again: unextract build

test: test-freetds

install-links: install-freetds-links

install-docs: install-freetds-docs

install-prefix: install-freetds-prefix

install: install-freetds

build: build-freetds

clean: clean-freetds

configed: configed-$(FREETDS_DIR)

config: config-$(FREETDS_DIR)

help: help-freetds

list-docs: list-freetds-docs

list-patch: list-freetds-patch

extract-patch: extract-freetds-patch

list: list-freetds

extract: extract-freetds

unextract: unextract-freetds

archive: archive-freetds

linked: freetds-linked

prefixed: freetds-prefixed

archived: freetds-archived

extracted: freetds-extracted

########################################################################
#
# freetds rules
#
########################################################################

#
# Help freetds
#
help-freetds: $(FREETDS_DIR)
	@($(FREETDS_CONFIGURE_PUSHD);\
	  (($(FREETDS_HELP)) || (exit 1));\
	  popd)

#
# Install freetds
#
install-freetds: configed-$(FREETDS_DIR)
	@(echo Installing $(FREETDS_DIR)...;\
	  $(FREETDS_MAKE_PUSHD);\
	  (($(FREETDS_MAKE) install) || (exit 1)) && \
	  ((touch $(FREETDS_MAKEDIR)/configed-$(FREETDS_DIR)) || (exit 1));\
	  popd)
	  
#
# Build freetds
#
build-freetds: configed-$(FREETDS_DIR)
	@(echo Building $(FREETDS_DIR)...;\
	  $(FREETDS_MAKE_PUSHD);\
	  (($(FREETDS_MAKE)) || (exit 1)) && \
	  ((touch $(FREETDS_MAKEDIR)/configed-$(FREETDS_DIR)) || (exit 1));\
	  popd)
	  
#
# Clean freetds
#
clean-freetds: configed-$(FREETDS_DIR)
	@(echo Cleaning $(FREETDS_DIR)...;\
	  $(FREETDS_MAKE_PUSHD);\
	  (($(FREETDS_MAKE) clean) || (exit 1)) && \
	  ((touch $(FREETDS_MAKEDIR)/configed-$(FREETDS_DIR)) || (exit 1));\
	  popd)
	  
#
# Test freetds
#
test-freetds: configed-$(FREETDS_DIR)
	@(echo Building test $(FREETDS_DIR)...;\
	  $(FREETDS_MAKE_PUSHD);\
	  (($(FREETDS_MAKE) test) || (exit 1)) && \
	  ((touch $(FREETDS_MAKEDIR)/configed-$(FREETDS_DIR)) || (exit 1));\
	  popd)
	  
#
# Config freetds
#
config-$(FREETDS_DIR): unconfig-$(FREETDS_DIR) configed-$(FREETDS_DIR)

unconfig-$(FREETDS_DIR):
	@(rm -f configed-$(FREETDS_DIR))

configed-$(FREETDS_DIR): $(FREETDS_DIR)
	@(echo Configing $(FREETDS_DIR)...;\
	  $(FREETDS_CONFIGURE_PUSHD);\
	  (($(FREETDS_CONFIGURE)) || (exit 1)) && \
	  ((touch $(FREETDS_DIR)) || (exit 1)) && \
	  ((touch $(FREETDS_MAKEDIR)/configed-$(FREETDS_DIR)) || (exit 1));\
	  popd)

########################################################################
# docs
########################################################################

#
# List freetds Docs
#
list-freetds-docs: $(FREETDS_DOCS_TGZ)
	@(echo Listing $(FREETDS_DOCS_TGZ)...;\
	  (($(FREETDS_LIST_DOCS_TGZ)) || (exit 1)))

#
# Install freetds Docs
#
install-freetds-docs: $(FREETDS_DOCS_PREFIX)
	@(echo Extracting $(FREETDS_DOCS_TGZ)...;\
	  (($(FREETDS_EXTRACT_DOCS_TGZ)) || (exit 1)))

########################################################################
# patch
########################################################################

#
# List freetds Patch
#
list-freetds-patch: $(FREETDS_PATCH_TGZ)
	@(echo Listing $(FREETDS_PATCH_TGZ)...;\
	  (($(FREETDS_LIST_PATCH_TGZ)) || (exit 1)))

#
# Extract freetds patch
#
extract-freetds-patch: $(FREETDS_DIR)
	@(echo Extracting $(FREETDS_PATCH_TGZ)...;\
	  (($(FREETDS_EXTRACT_PATCH_TGZ)) || (exit 1)))

########################################################################
# archive
########################################################################

#
# List freetds
#
list-freetds: 
	@(echo Listing $(FREETDS_TGZ)...;\
	  (($(FREETDS_LIST_TGZ)) || (exit 1)))

#
# freetds extracted
#
freetds-extracted: 
	@(echo $(FREETDS_EXTRACT) $(FREETDS_TGZ))

#
# Extract freetds
#
extract-freetds: unextract-freetds $(FREETDS_DIR)

unextract-freetds: unconfig-$(FREETDS_DIR)
	@(echo Removing $(FREETDS_DIR)...;\
	  (($(FREETDS_REMOVE_DIR)) || (exit 1)))

$(FREETDS_DIR): $(FREETDS_TGZ)
	@(echo Extracting $(FREETDS_TGZ)...;\
	  (($(FREETDS_EXTRACT_TGZ)) || (exit 1)) && \
	  (($(FREETDS_TOUCH_EXTRACT)) || (exit 1)))
	  
#
# freetds archived
#
freetds-archived: 
	@(echo $(FREETDS_TGZ))
	  
#
# Archive freetds
#
archive-freetds: 
	@(echo Archiving $(FREETDS_DIR) to $(FREETDS_TGZ)...;\
	  (($(FREETDS_ARCHIVE) $(FREETDS_TGZ) $(FREETDS_DIR)) || (exit 1)))

########################################################################
# links
########################################################################

#
# freetds linked
#
freetds-linked: 
	@echo link is $(FREETDS_LINK_NAME) "->" $(FREETDS_PREFIX)
	  
#
# Install freetds links
#
install-freetds-links: 
	@((echo removing $(FREETDS_LINK_NAME)) && \
	  ((rm -f $(FREETDS_LINK_NAME)) || (exit 1)) && \
	  (echo Linking $(FREETDS_LINK_NAME) "->" $(FREETDS_PREFIX)) && \
	  ((ln -s $(FREETDS_PREFIX) $(FREETDS_LINK_NAME)) || (exit 1)))
	  
########################################################################
# prefix
########################################################################

#
# freetds prefixed
#
freetds-prefixed: 
	@((echo prefix is $(FREETDS_PREFIX)) && \
	  (echo exec prefix is $(FREETDS_EXEC_PREFIX)) && \
	  (echo conf prefix is $(FREETDS_CONF_PREFIX)) && \
	  (echo docs prefix is $(FREETDS_DOCS_PREFIX)))
	  
#
# Install freetds prefix
#
install-freetds-prefix: 
	@((echo makeing $(FREETDS_PREFIX)) && \
	  ((mkdir -p $(FREETDS_PREFIX)) || (exit 1)) && \
	  (echo makeing $(FREETDS_EXEC_PREFIX)) && \
	  ((mkdir -p $(FREETDS_EXEC_PREFIX)) || (exit 1)))
	  
$(FREETDS_PREFIX):
	@(echo Makeing Directory $(FREETDS_PREFIX)...;\
	  (($(FREETDS_MKDIR) $(FREETDS_PREFIX)) || (exit 1)))

$(FREETDS_EXEC_PREFIX):
	@(echo Makeing Directory $(FREETDS_EXEC_PREFIX)...;\
	  (($(FREETDS_MKDIR) $(FREETDS_EXEC_PREFIX)) || (exit 1)))

$(FREETDS_CONF_PREFIX):
	@(echo Makeing Directory $(FREETDS_CONF_PREFIX)...;\
	  (($(FREETDS_MKDIR) $(FREETDS_CONF_PREFIX)) || (exit 1)))

$(FREETDS_DOCS_PREFIX):
	@(echo Makeing Directory $(FREETDS_DOCS_PREFIX)...;\
	  (($(FREETDS_MKDIR) $(FREETDS_DOCS_PREFIX)) || (exit 1)))




        

